// New Test Project Game. All Rights Reserved.


#include "UI/GameHUD.h"
#include "Blueprint/UserWidget.h"
#include "NewTestProject/NewTestProjectGameMode.h"

DEFINE_LOG_CATEGORY_STATIC(LogNTPGameHUD, All, All);

void AGameHUD::BeginPlay()
{
	if (GetWorld()) 
	{
		const auto GameMode = Cast<ANewTestProjectGameMode>(GetWorld()->GetAuthGameMode());
		if (GameMode) 
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &AGameHUD::OnMatchStateChanged);
		}
	}
}

void AGameHUD::OnMatchStateChanged(EMatchState State)
{
	UE_LOG(LogNTPGameHUD, Error, TEXT("Match state changed: %s"), *UEnum::GetValueAsString(State));
}
