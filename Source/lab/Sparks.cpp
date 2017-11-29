// Fill out your copyright notice in the Description page of Project Settings.

#include "Sparks.h"


// Sets default values
ASparks::ASparks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASparks::BeginPlay()
{
	Super::BeginPlay();
	this->fr = GetActorLocation();
	
}

// Called every frame
void ASparks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DeltaTime *= speed;
	float DeltaDis = FMath::Sin(RunningTime / A * 3.14 / 2);
	FVector NewLocation = fr + (to - fr) * DeltaDis;
	SetActorLocation(NewLocation);
	RunningTime += DeltaTime;
	if (RunningTime > A) RunningTime = 0;
}

