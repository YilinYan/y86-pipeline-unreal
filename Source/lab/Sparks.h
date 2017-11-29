// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sparks.generated.h"

UCLASS()
class LAB_API ASparks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASparks();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ASparks)
		float RunningTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ASparks)
		float A = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ASparks)
		float speed = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ASparks)
		FVector fr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ASparks)
		FVector to;
	
	
};
