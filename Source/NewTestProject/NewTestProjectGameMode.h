// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Public/CoreTypes.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NewTestProjectGameMode.generated.h"

UCLASS(minimalapi)
class ANewTestProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANewTestProjectGameMode();

	virtual void StartPlay() override;

	FOnMatchStateChangedSignature OnMatchStateChanged;

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;
private:
	EMatchState MatchState = EMatchState::WaitingToStart;

	void SetMatchState(EMatchState State);
};



