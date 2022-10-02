// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

class UButton;

UCLASS()
class NEWTESTPROJECT_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* ClearPauseButton;
    virtual void NativeOnInitialized() override;
private:
	UFUNCTION()
		void OnClearPause();
	
};
