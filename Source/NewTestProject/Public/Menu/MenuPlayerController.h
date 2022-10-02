// New Test Project Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NEWTESTPROJECT_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	
};
