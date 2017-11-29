// Fill out your copyright notice in the Description page of Project Settings.

#include "Execute.h"
#include "DecodeAndWrite.h"
#include "Fetch.h"
#include "Memory.h"

// Sets default values
AExecute::AExecute()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExecute::BeginPlay()
{
	Super::BeginPlay();
	icode = '#';
	e_icode = '#';
}

FString AExecute::TOHEX(int32 a) {
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
void AExecute::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExecute::updateVal() {
	icode = decode->e_icode;
	ifun = decode->e_ifun;
	valC = decode->e_valC;
	valA = decode->e_valA;
	valB = decode->e_valB;
	dstE = decode->e_dstE;
	dstM = decode->e_dstM;
	srcA = decode->e_srcA;
	srcB = decode->e_srcB;
}

void AExecute::update() {
	this->updateVal();


	//update output
	o_icode = (FString)" " + (TCHAR)(icode);
	o_ifun = (FString)" " + (TCHAR)(ifun);
	o_dstE = (FString)" " + (TCHAR)(dstE);
	o_dstM = (FString)" " + (TCHAR)(dstM);
	o_srcA = (FString)" " + (TCHAR)(srcA);
	o_srcB = (FString)" " + (TCHAR)(srcB);
	o_valC = (FString)" " + TOHEX(valC);
	o_valA = (FString)" " + TOHEX(valA);
	o_valB = (FString)" " + TOHEX(valB);



	if (icode == '#' || icode == '1') { //ADD II
		e_icode = icode;
		return;
	}

	if (E_bubble == 1) {
		E_bubble = 0;
		memory->M_bubble = 1;
		return;
	}

	//get aluA
	switch (icode)
	{
	case'6':
	case'2':
		aluA = valA;
		break;
	case'3':
	case'4':
	case'5':
		aluA = valC;
		break;
	case'8':
	case'a':
		aluA = -4;
		break;
	case'9':
	case'b':
		aluA = 4;
		break;
	default:
		break;
	}

	//get aluB
	switch (icode)
	{
	case'4':
	case'5':
	case'6':
	case'8':
	case'9':
	case'a':
	case'b':
		aluB = valB;
		break;
	case'2':
	case'3':
		aluB = 0;
		break;
	default:
		break;
	}

	//get aluFun
	if (icode == '6') aluFun = ifun;
	else aluFun = '0';

	//update output
	o_aluA = (FString)" " + TOHEX(aluA);
	o_aluB = (FString)" " + TOHEX(aluB);
	o_aluFun = (FString)" " + (TCHAR)(aluFun);



	//get e_valE 
	switch (aluFun)
	{
	case'0':
		e_valE = aluA + aluB;
		break;
	case'1':
		e_valE = aluB - aluA;
		break;
	case'2':
		e_valE = aluA & aluB;
		break;
	case'3':
		e_valE = aluA ^ aluB;
		break;
	default:
		break;
	}


	if (icode == '6') set_cc = 1;
	else set_cc = 0;

	if (set_cc == 1) {

		//get set_ZF
		if (e_valE == 0) set_ZF = 1;
		else set_ZF = 0;

		//get set_SF
		if (e_valE < 0) set_SF = 1;
		else set_SF = 0;

		//get set_OF
		switch (ifun) {
		case'0':
			if (((aluA < 0) == (aluB < 0)) && ((e_valE < 0) != (aluA < 0)))
				set_OF = 1;
			else set_OF = 0;
			break;
		case'1':
			if (((aluA < 0) == (aluB > 0)) && ((e_valE < 0) != (aluA < 0)))
				set_OF = 1;
			else set_OF = 0;
			break;
		case'2':
		case'3':
			set_OF = 0;
			break;
		default:
			break;
		}
	}

	if (icode == '7') {
		switch (ifun)
		{
		case'0':
			e_Cnd = 1;
			break;
		case'1':
			e_Cnd = (set_SF ^ set_OF) | set_ZF;
			break;
		case'2':
			e_Cnd = (set_SF ^ set_OF);
			break;
		case'3':
			e_Cnd = set_ZF;
			break;
		case'4':
			e_Cnd = set_ZF ^ 1;
			break;
		case'5':
			e_Cnd = (set_SF ^ set_OF) ^ 1;
			break;
		case'6':
			e_Cnd = ((set_SF ^ set_OF) ^ 1) & (set_ZF ^ 1);
			break;
		default:
			break;
		}
	}
	else e_Cnd = 1;


	//get e_icode
	e_icode = icode;

	//get e_valA
	e_valA = valA;

	//get e_dstM
	e_dstM = dstM;

	//to do e_dstE
	e_dstE = dstE;


}


