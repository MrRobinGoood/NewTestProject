// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

class UButton;

UCLASS()
class NEWTESTPROJECT_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* StartGameButton;
	
	virtual void NativeOnInitialized() override;
private:
	UFUNCTION()
	void OnStartGame();
	
};
