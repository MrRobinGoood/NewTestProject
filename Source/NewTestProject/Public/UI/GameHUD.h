// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NewTestProject/Public/CoreTypes.h"
#include "GameHUD.generated.h"

UCLASS()
class NEWTESTPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

private:
	UPROPERTY()
	TMap<EMatchState, UUserWidget*> GameWidgets;

	UPROPERTY()
	UUserWidget* CurrentWidget = nullptr;
	
	void OnMatchStateChanged(EMatchState State);	
};
