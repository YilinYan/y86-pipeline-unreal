// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Execute.generated.h"

UCLASS()
class LAB_API AExecute : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExecute();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class ADecodeAndWrite* decode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AFetch* fetch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AMemory* memory;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 ifun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 srcA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 srcB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 dstM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 valA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 valB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 valC;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 aluFun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 aluA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 aluB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 set_cc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 set_OF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 set_ZF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 set_SF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 E_bubble;

	//new val
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 e_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 e_Cnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 e_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		uint8 e_dstM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 e_valE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AExecute)
		int32 e_valA;

	//out put
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString output;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_ifun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_srcA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_srcB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_aluA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_aluB;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_aluFun;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = AExecute)
		void update();
	void updateVal();
	FString TOHEX(int32);
	
};
