// New Test Project Game. All Rights Reserved.


#include "Menu/MenuGameModeBase.h"
#include "Menu/MenuPlayerController.h"
#include "Menu/UI/MenuHUD.h"


AMenuGameModeBase::AMenuGameModeBase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}


