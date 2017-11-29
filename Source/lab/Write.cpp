// Fill out your copyright notice in the Description page of Project Settings.

#include "Write.h"
#include "Memory.h"

// Sets default values
AWrite::AWrite()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWrite::BeginPlay()
{
	Super::BeginPlay();
	icode = '#';
	dstE = dstM = '#';
}

FString AWrite::TOHEX(int32 a) {
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

// Called every frame
void AWrite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWrite::updateVal() {
	valE = memory->e_valE;
	valM = memory->e_valM;
	icode = memory->e_icode;
	dstE = memory->e_dstE;
	dstM = memory->e_dstM;
}

void AWrite::update() {
	this->updateVal();


	//update output
	o_icode = (FString)" " + (TCHAR)(icode);
	o_dstE = (FString)" " + (TCHAR)(dstE);
	o_dstM = (FString)" " + (TCHAR)(dstM);
	o_valE = (FString)" " + TOHEX(valE);
	o_valM = (FString)" " + TOHEX(valM);



	if (W_bubble == 1) {
		W_bubble = 0;
		return;
	}

	if (icode == '#' || icode == '1') return;

	output = (FString)"icode = " + (TCHAR)(icode) + '\n';
	output += (FString)"valE = " + FString::FromInt(valE) + '\n';
	output += (FString)"valM = " + FString::FromInt(valM) + '\n';
	output += (FString)"dstE = " + (TCHAR)(dstE) + '\n';
	output += (FString)"dstM = " + (TCHAR)(dstM) + '\n';

}



