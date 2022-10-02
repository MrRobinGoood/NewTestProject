// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NewTestProject/Public/CoreTypes.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class NEWTESTPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	void OnMatchStateChanged(EMatchState State);
};
