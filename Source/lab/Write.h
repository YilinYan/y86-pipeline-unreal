// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Write.generated.h"

UCLASS()
class LAB_API AWrite : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWrite();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Reference)
		class AMemory* memory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		int32 valE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		int32 valM;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		uint8 icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		uint8 dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		uint8 dstM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AWrite)
		uint8 W_bubble;

	//out put
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString output;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_icode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_Cnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valM;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_valE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OUTPUT)
		FString o_dstM;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = AWrite)
		void update();
	void updateVal();
	FString TOHEX(int32);
	
	
};
