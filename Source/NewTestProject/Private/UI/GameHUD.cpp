// New Test Project Game. All Rights Reserved.


#include "UI/GameHUD.h"
#include "Blueprint/UserWidget.h"
#include "NewTestProject/NewTestProjectGameMode.h"

DEFINE_LOG_CATEGORY_STATIC(LogNTPGameHUD, All, All);

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	GameWidgets.Add(EMatchState::Pause, CreateWidget<UUserWidget>(GetWorld(), PauseWidgetClass));

	for (auto GameWidgetPair : GameWidgets)
	{
		const auto GameWidget = GameWidgetPair.Value;
		if (!GameWidget) continue;

		GameWidget->AddToViewport();
		GameWidget->SetVisibility(ESlateVisibility::Hidden);
	}

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
	if (CurrentWidget)
	{
		UE_LOG(LogNTPGameHUD, Error, TEXT("YESYESYESYESYESYESYESYESYESUEYSYEYSE"));
		CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	
	if (GameWidgets.Contains(State)) 
	{
		UE_LOG(LogNTPGameHUD, Error, TEXT("CONCRANTE"));
		CurrentWidget = GameWidgets[State];
	}
	
	if (CurrentWidget)
	{
		UE_LOG(LogNTPGameHUD, Error, TEXT("NO   NO   NO   NO    NO"));
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}


	UE_LOG(LogNTPGameHUD, Display, TEXT("Match state changed: %s"), *UEnum::GetValueAsString(State));
}
