// New Test Project Game. All Rights Reserved.


#include "NewTestProject/Public/UI/PauseWidget.h"
#include "Gameframework/GameModeBase.h"
#include "Components/Button.h"

void UPauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ClearPauseButton)
	{
		ClearPauseButton->OnClicked.AddDynamic(this, &UPauseWidget::OnClearPause);
	}
}

void UPauseWidget::OnClearPause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode()) return;
	
	GetWorld()->GetAuthGameMode()->ClearPause();
}
