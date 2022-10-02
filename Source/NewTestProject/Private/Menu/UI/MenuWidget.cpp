// New Test Project Game. All Rights Reserved.


#include "Menu/UI/MenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "NTPGameInstance.h"

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMenuWidget::OnStartGame);
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
