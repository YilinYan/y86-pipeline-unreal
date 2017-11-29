// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveCube.generated.h"

UCLASS()
class LAB_API AMoveCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMOveCube)
	float RunningTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMOveCube)
	float A = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AMOveCube)
	float speed = 2.0f;
	
	
};
