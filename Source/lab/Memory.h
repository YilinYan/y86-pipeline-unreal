// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Memory.generated.h"

UCLASS()
class LAB_API AMemory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AExecute* execute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AWrite* write;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 Cnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 dstM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 M_bubble;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		int32 valA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		int32 valE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 mem_read;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 mem_write;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		int32 addr;

	uint8 mem[100000 * 4];
	
	//new val
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 e_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 e_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		uint8 e_dstM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		int32 e_valE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMemory)
		int32 e_valM;

	//out put
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString output;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_Cnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_addr;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = AMemory)
		void update();
	void updateVal();
	FString TOHEX(int32);

	
	
};
