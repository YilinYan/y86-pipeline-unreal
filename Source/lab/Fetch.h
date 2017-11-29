// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fetch.generated.h"

UCLASS()
class LAB_API AFetch : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFetch();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class ADecodeAndWrite* decode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AMemory* memory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AExecute* execute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AWrite* write;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		FString input;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 valP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 prePC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 f_PC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 ff_PC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 valC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 ifun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 rA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 rB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 need_reg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 need_valC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		uint8 F_stall;

	// OUT PUT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString output;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_ifun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_f_PC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_prePC;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = AFetch)
		void readIntoMem();
	UFUNCTION(BlueprintCallable, Category = AFetch)
		void update();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AFetch)
		int32 count;

	FString TOHEX(int32);

	
};
