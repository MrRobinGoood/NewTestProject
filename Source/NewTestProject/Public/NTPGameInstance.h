// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NTPGameInstance.generated.h"

UCLASS()
class NEWTESTPROJECT_API UNTPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetStartupLevelName() const { return StartupLevelName; }
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName StartupLevelName = NAME_None;
	
};
