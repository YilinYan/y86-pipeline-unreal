// Fill out your copyright notice in the Description page of Project Settings.

#include "Fetch.h"
#include "Memory.h"
#include "DecodeAndWrite.h"
#include "Execute.h"
#include "Write.h"

// Sets default values
AFetch::AFetch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFetch::BeginPlay()
{
	Super::BeginPlay();
	f_PC = prePC = 0;
	count = 0;
	icode = '#';
}

// Called every frame
void AFetch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FString AFetch::TOHEX(int32 a) {
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

void AFetch::readIntoMem() {
	int32 len = input.Len();

	for (int i = 0; i < len; i += 2) {
		int a = (input[i] >= 'a') ? (input[i] - 'a' + 10) : (input[i] - '0');  // ADD 10
		int b = (input[i + 1] >= 'a') ? (input[i + 1] - 'a' + 10) : (input[i + 1] - '0');
		memory->mem[i / 2] = a * 16 + b;
	}
}

void AFetch::update() {
	if (execute->icode == '7' && execute->e_Cnd == 0 && memory->icode != '7')   //exec
		ff_PC = execute->valA;

	else if (write->icode == '9')
		ff_PC = write->valM;
	//ADD II
	else if (memory->icode == '9') {
		decode->D_bubble = 1;
		execute->E_bubble = 1;
		memory->M_bubble = 1;
	}
	else if (execute->icode == '9') {
		decode->D_bubble = 1;
		execute->E_bubble = 1;
	}
	else if (decode->icode == '9') {
		decode->D_bubble = 1;
	}
	else
		ff_PC = prePC;

	f_PC = ff_PC * 2;

	if (f_PC >= input.Len())
		return;

	//
	if ((execute->icode == '5' || execute->icode == 'b')
		&& (execute->dstM == decode->e_srcA || execute->dstM == decode->e_srcB))
		F_stall = 1;
	else if (write->icode == '9')
		F_stall = 0;
	else if ((decode->icode == '9' || execute->icode == '9' || memory->icode == '9'))
		F_stall = 1;
	else
		F_stall = 0;

	if (F_stall == 1)  return;

	icode = input[f_PC];
	ifun = input[f_PC + 1];


	//update output
	o_icode = (FString)" " + (TCHAR)(icode);
	o_ifun = (FString)" " + (TCHAR)(ifun);
	o_f_PC = (FString)" " + TOHEX(f_PC);
	o_prePC = (FString)" " + TOHEX(prePC);


	if (icode == '#' || icode == '1') return;

	switch (icode) {  //count valP
	case '3':
	case '4':
	case '5':
		valP = ff_PC + 6;
		break;
	case '7':
	case '8':
		valP = ff_PC + 5;
		break;
	case '2':
	case '6':
	case 'a':
	case 'b':
		valP = ff_PC + 2;
		break;
	case '9':
	case '0':
	case '1':
		valP = ff_PC + 1;
	}

	switch (icode) { // count need reg / valC
	case '3':
	case '2':
	case '5':
	case '4':
	case '6':
	case 'a':
	case 'b':
		need_reg = 1;
		break;
	default:
		need_reg = 0;
	}

	switch (icode) {
	case '3':
	case '5':
	case '4':
	case '7':
	case '8':
		need_valC = 1;
		break;
	default:
		need_valC = 0;
	}

	if (need_reg) rA = input[f_PC + 2], rB = input[f_PC + 3]; // rA rB
	if (need_valC) {
		int fr = f_PC + 2;
		if (need_reg) fr += 2;

		valC = 0;
		for (int i = fr + 6; i >= fr; i -= 2) {  //count valC
			valC *= 16 * 16;
			int a = (input[i] >= 'a') ? (input[i] - 'a' + 10) : (input[i] - '0');  // ADD 10 
			int b = (input[i + 1] >= 'a') ? (input[i + 1] - 'a' + 10) : (input[i + 1] - '0');
			valC += a * 16 + b;
		}
	}

	//get prePC
	if (icode == '7' || icode == '8') prePC = valC; 
	else prePC = valP;

}

