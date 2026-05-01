// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "WanliGASMonitorTypes.h"

class SWindow;
class SWanliGASMonitorWidget;

class FWanli_GASMonitorEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void EnsureWindowCreated();
	void OnGASMonitorEvent(const FWanliGASMonitorEvent& Event);

	TSharedPtr<SWindow> MonitorWindow;
	TSharedPtr<SWanliGASMonitorWidget> MonitorWidget;
	FDelegateHandle EventHandle;
};
