#include "TestPlugin/Public/TestPlugin_Settings.h"

UTestPlugin_Settings::UTestPlugin_Settings(const FObjectInitializer& obj)
{
	UseRelativePath = false;
	SaveDirectory = "SaveGame/";
	MainSaveName = "MainSave";
	UseAsyncSave = true;
	SaveSlotBaseName = "Save";
	AutoSaveBaseName = "AutoSave";
	AutoSaveCount = 4;
}