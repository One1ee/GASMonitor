// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WanliGASMonitorTypes.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWanliGASMonitorEvent, const FWanliGASMonitorEvent&);

/**
 * Singleton event bus between the runtime component and the editor Slate window.
 * The runtime side calls PushEvent(); the editor side binds to OnEventReceived.
 */
class WANLI_GASMONITOR_API FWanliGASMonitorUIManager
{
public:
	static FWanliGASMonitorUIManager& Get();

	void PushEvent(const FWanliGASMonitorEvent& Event);

	FOnWanliGASMonitorEvent OnEventReceived;

private:
	FWanliGASMonitorUIManager() = default;
	FWanliGASMonitorUIManager(const FWanliGASMonitorUIManager&) = delete;
	FWanliGASMonitorUIManager& operator=(const FWanliGASMonitorUIManager&) = delete;
};
