// Fill out your copyright notice in the Description page of Project Settings.

#include "FileLoad.h"


bool UFileLoad::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UFileLoad::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}


FString UFileLoad::FileLoadAndReturnString(FString FileNameA)
{
	FString myString;
	bool myBool = true;

	myBool = FFileHelper::LoadFileToString(myString, *(FPaths::GameDir() + FileNameA));
	return myString;
}

