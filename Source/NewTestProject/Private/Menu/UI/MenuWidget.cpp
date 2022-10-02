// New Test Project Game. All Rights Reserved.


#include "Menu/UI/MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "NTPGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMenuWidget::OnStartGame);
	}

	if (QuitGameButton)
	{
		QuitGameButton->OnClicked.AddDynamic(this, &UMenuWidget::OnQuitGame);
	}
}

void UMenuWidget::OnStartGame()
{
	
	if (!GetWorld()) return;

	const auto NTPGameInstance = GetWorld()->GetGameInstance<UNTPGameInstance>();
	if (!NTPGameInstance) return;

	if (NTPGameInstance->GetStartupLevelName().IsNone())
	{		
		return;
	}
	
	UGameplayStatics::OpenLevel(this, NTPGameInstance->GetStartupLevelName()); 
	
}

void UMenuWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(),EQuitPreference::Quit,true);
}
