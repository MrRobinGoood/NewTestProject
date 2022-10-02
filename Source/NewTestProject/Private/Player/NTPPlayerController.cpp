// New Test Project Game. All Rights Reserved.


#include "Player/NTPPlayerController.h"
#include "NewTestProject/NewTestProjectGameMode.h"

void ANTPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetWorld())
	{
		const auto GameMode = Cast<ANewTestProjectGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &ANTPPlayerController::OnMatchStateChanged);
		}
	}
}

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

void ANTPPlayerController::OnMatchStateChanged(EMatchState State)
{
	if (State == EMatchState::InProgress) 
	{
		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	else
	{
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}
