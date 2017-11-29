// Fill out your copyright notice in the Description page of Project Settings.

#include "Memory.h"
#include "Execute.h"
#include "Write.h"

// Sets default values
AMemory::AMemory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FString AMemory::TOHEX(int32 a) {
	uint32 A = a;
	FString ret = "";
	TCHAR tp[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	while (A) {
		ret += tp[A % 16];
		A /= 16;
	}
	ret += "0x0";
	ret = ret.FString::Reverse();
	return ret;
};

// Called when the game starts or when spawned
void AMemory::BeginPlay()
{
	Super::BeginPlay();
	icode = '#';
	e_icode = '#';
	memset(mem, 0, sizeof mem);
}

// Called every frame
void AMemory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMemory::updateVal() {
	icode = execute->e_icode;
	Cnd = execute->e_Cnd;
	dstE = execute->e_dstE;
	dstM = execute->e_dstM;
	valA = execute->e_valA;
	valE = execute->e_valE;
}

void AMemory::update() {
	this->updateVal();

	//update output
	o_icode = (FString)" " + (TCHAR)(icode);
	o_dstE = (FString)" " + (TCHAR)(dstE);
	o_dstM = (FString)" " + (TCHAR)(dstM);
	o_valE = (FString)" " + TOHEX(valE);
	o_valA = (FString)" " + TOHEX(valA);
	o_Cnd = (FString)" " + (Cnd ? "1" : "0");

	if (M_bubble == 1) {
		M_bubble = 0;
		write->W_bubble = 1;
		return;
	}

	if (icode == '#' || icode == '1') {
		e_icode = icode;
		return;
	}
	if (icode == '9' || icode == '5' || icode == 'b')
		mem_read = 1;
	else mem_read = 0;

	if (icode == '4' || icode == '8' || icode == 'a')
		mem_write = 1;
	else mem_write = 0;

	//get addr
	if (icode == '4' || icode == '5' || icode == '8' || icode == 'a')
		addr = valE;
	else if (icode == '9' || icode == 'b')
		addr = valA;
	else
		addr = addr;



	//update output
	o_addr = (FString)" " + TOHEX(addr);



	// get e_..
	e_icode = icode;
	e_dstE = dstE;
	e_dstM = dstM;
	e_valE = valE;

	//read e_valM
	if (mem_read) {
		e_valM = 0;
		for (int i = addr + 3; i >= addr; --i) { 
			e_valM *= 16 * 16;
			e_valM += mem[i];
		}
	}

	// write back
	if (mem_write) {
		int tp = valA;
		for (int i = addr; i < addr + 4; ++i) {
			mem[i] = tp % (16 * 16);
			tp /= (16 * 16);
		}
	}


}

