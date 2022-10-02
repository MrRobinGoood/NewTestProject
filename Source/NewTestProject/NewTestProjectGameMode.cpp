// Copyright Epic Games, Inc. All Rights Reserved.

#include "NewTestProjectGameMode.h"
#include "NewTestProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Player/NTPPlayerController.h"

ANewTestProjectGameMode::ANewTestProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ANewTestProjectGameMode::StartPlay()
{
	Super::StartPlay();
	
	SetMatchState(EMatchState::InProgress);
}

bool ANewTestProjectGameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{	
	const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);

	if (PauseSet) 
	{
	SetMatchState(EMatchState::Pause);
	}

	return PauseSet;
}

void ANewTestProjectGameMode::SetMatchState(EMatchState State)
{	
	if (MatchState == State) return;

	MatchState = State;
	OnMatchStateChanged.Broadcast(MatchState);
}
