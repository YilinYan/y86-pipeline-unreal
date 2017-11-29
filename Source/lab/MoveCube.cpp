// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveCube.h"


// Sets default values
AMoveCube::AMoveCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMoveCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DeltaTime *= speed;
	float DeltaDis = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	FVector NewLocation = GetActorLocation();
	NewLocation.Z += DeltaDis * A;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

