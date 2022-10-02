// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NTPPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NEWTESTPROJECT_API ANTPPlayerController : public APlayerController
{
	GENERATED_BODY()
		

public:
	
	

protected:
	virtual void SetupInputComponent() override;

private:
	void OnPauseGame();

};
