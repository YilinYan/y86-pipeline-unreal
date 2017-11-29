// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecodeAndWrite.generated.h"

UCLASS()
class LAB_API ADecodeAndWrite : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecodeAndWrite();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AFetch* fetch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AMemory* memory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AExecute* execute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AWrite* write;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		int32 valC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		int32 valP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ADecodeAndWrite)
		TArray<int32> reg;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 ifun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 rA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 rB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 D_stall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 D_bubble;

	//new val
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		int32 e_valA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		int32 e_valB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		int32 e_valC;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_srcA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_srcB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_dstM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ADecodeAndWrite)
		uint8 e_ifun;


	//out put
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString output;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_ifun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_rA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_rB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_reg;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = ADecodeAndWrite)
		void update();
	void ADecodeAndWrite::updateVal();
	FString TOHEX(int32);
};
