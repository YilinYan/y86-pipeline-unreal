// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileLoad.generated.h"

/**
 * 
 */
UCLASS()
class LAB_API UFileLoad : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:

		UFUNCTION(BlueprintCallable, Category = "save")
			static bool FileSaveString(FString SaveTextB, FString FileNameB);

		UFUNCTION(BlueprintCallable, Category = "save")
			static bool FileLoadString(FString FileNameA, FString& SaveTextA);

		UFUNCTION(BlueprintCallable, Category = "save")
			static FString FileLoadAndReturnString(FString FileNameA);
	
	
	
};
