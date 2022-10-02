// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestPlugin_Settings.generated.h"

/**
 *
 */
UCLASS(config = MySetting)
class TESTPLUGIN_API UTestPlugin_Settings : public UObject
{
	GENERATED_BODY()

public:
	UTestPlugin_Settings(const FObjectInitializer& obj);

	UPROPERTY(Config, EditAnywhere, Category = "General settings")
		bool UseRelativePath;
	
	UPROPERTY(Config, EditAnywhere, Category = "General settings")
		FString SaveDirectory;

	UPROPERTY(Config, EditAnywhere, Category = "General settings")
		FString MainSaveName;

	UPROPERTY(Config, EditAnywhere, Category = "Save/Load")
		bool UseAsyncSave;

	UPROPERTY(Config, EditAnywhere, Category = "Save/Load")
		FString SaveSlotBaseName;

	UPROPERTY(Config, EditAnywhere, Category = "Auto Save")
		FString AutoSaveBaseName;

	UPROPERTY(Config, EditAnywhere, Category = "Auto Save")
		int32 AutoSaveCount;
};