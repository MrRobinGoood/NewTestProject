// New Test Project Game. All Rights Reserved.


#include "Player/NTPPlayerController.h"
#include "GameFramework/GameModeBase.h"

void ANTPPlayerController::SetupInputComponent()
{	
	Super::SetupInputComponent();
	if (!InputComponent) return;

	InputComponent->BindAction("PauseGame", IE_Pressed, this, &ANTPPlayerController::OnPauseGame);
}

void ANTPPlayerController::OnPauseGame()
{
	

	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;

	GetWorld()->GetAuthGameMode()->SetPause(this);
}
