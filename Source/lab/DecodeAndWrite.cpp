// Fill out your copyright notice in the Description page of Project Settings.

#include "DecodeAndWrite.h"
#include "Fetch.h"
#include "Memory.h"
#include "Execute.h"
#include "Write.h"

// Sets default values
ADecodeAndWrite::ADecodeAndWrite()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADecodeAndWrite::BeginPlay()
{
	Super::BeginPlay();
	icode = '#';
	e_icode = '#';
}

FString ADecodeAndWrite::TOHEX(int32 a) {
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
void ADecodeAndWrite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADecodeAndWrite::updateVal() {
	valC = fetch->valC;
	valP = fetch->valP;

	icode = fetch->icode;
	ifun = fetch->ifun;

	rA = fetch->rA;
	rB = fetch->rB;

	if (write->icode != '#' && write->icode != '1') {
		if (write->dstE != '#') reg[write->dstE - '0'] = write->valE;
		if (write->dstM != '#') reg[write->dstM - '0'] = write->valM;
	}
}

void ADecodeAndWrite::update() {
	this->updateVal();


	//update output
	o_icode = (FString)" " + (TCHAR)(icode);
	o_ifun = (FString)" " + (TCHAR)(ifun);
	o_rA = (FString)" " + (TCHAR)(rA);
	o_rB = (FString)" " + (TCHAR)(rB);
	o_valC = (FString)" " + TOHEX(valC);
	o_valP = (FString)" " + TOHEX(valP);
	o_reg = (FString)"%eax :  " + TOHEX(reg[0]) + '\n';
	o_reg += (FString)"%ecx :  " + TOHEX(reg[1]) + '\n';
	o_reg += (FString)"%edx :  " + TOHEX(reg[2]) + '\n';
	o_reg += (FString)"%ebx :  " + TOHEX(reg[3]) + '\n';	
	o_reg += (FString)"%esp :  " + TOHEX(reg[4]) + '\n';
	o_reg += (FString)"%ebp :  " + TOHEX(reg[5]) + '\n';
	o_reg += (FString)"%esi :  " + TOHEX(reg[6]) + '\n';
	o_reg += (FString)"%edi :  " + TOHEX(reg[7]) + '\n';



	if (D_bubble == 1) {
		D_bubble = 0;
		execute->E_bubble = 1;
		return;
	}

	if (icode == '#' || icode == '1') {
		e_icode = icode;
		return;
	}

	//get e_srcA
	switch (icode) {
	case'2':
	case'4':
	case'5':
	case'6':
	case'a':
		e_srcA = rA;
		break;
	case 'b':
	case '9':
		e_srcA = '4';
		break;
	default:
		e_srcA = '#'; // ADD II
		break;
	}

	//get e_srcB
	switch (icode) {
	case'2':
	case'3':
	case'4':
	case'5':
	case'6':
		e_srcB = rB;
		break;
	case'8':
	case'9':
	case'a':
	case'b':
		e_srcB = '4';
		break;
	default:
		e_srcB = '#'; //ADD II
		break;
	}


	//get d_bubble 
	if ((execute->icode == '5' || execute->icode == 'b')
		&& (execute->dstM == e_srcA || execute->dstM == e_srcB)) //ADD II
		execute->E_bubble = 1;
	else if (execute->icode == '7' && execute->e_Cnd == 0)
		execute->E_bubble = 1;
	else
		D_bubble = 0;



	//get e_valA
	if (icode == '8' || icode == '7') e_valA = valP;
	else {
		if (e_srcA == execute->e_dstE) {
			e_valA = execute->e_valE;
		}
		else if (e_srcA == memory->dstM) {
			e_valA = memory->e_valM;
		}
		else if (e_srcA == memory->dstE) {
			e_valA = memory->valE;
		}
		else if (e_srcA == write->dstM) {
			e_valA = write->valM;
		}
		else if (e_srcA == write->dstE) {
			e_valA = write->valE;
		}
		else {
			e_valA = reg[e_srcA - '0'];
		}
	}

	//get e_valB    
	if (e_srcB == execute->e_dstE) {
		e_valB = execute->e_valE;
	}
	else if (e_srcB == memory->dstM) {
		e_valB = memory->e_valM;
	}
	else if (e_srcB == memory->dstE) {
		e_valB = memory->valE;
	}
	else if (e_srcB == write->dstM) {
		e_valB = write->valM;
	}
	else if (e_srcB == write->dstE) {
		e_valB = write->valE;
	}
	else {
		e_valB = reg[e_srcB - '0'];
	}

	//get e_dstE
	switch (icode) {
	case '2':
	case '3':
	case '6':
		e_dstE = rB;
		break;
	case 'a':
	case 'b':
	case '8':
	case '9':
		e_dstE = '4';
		break;
	default:
		e_dstE = '#';
		break;
	}

	//get e_dstM
	if (icode == 'b' || icode == '5') e_dstM = rA;
	else e_dstM = '#';

	e_icode = icode;
	e_ifun = ifun;
	e_valC = valC;


}
