#pragma once

#include "CoreTypes.generated.h"


UENUM(BlueprintType)
enum class EMatchState : uint8
{
	WaitingToStart = 0,
	InProgress,
	Pause
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMatchStateChangedSignature, EMatchState); 