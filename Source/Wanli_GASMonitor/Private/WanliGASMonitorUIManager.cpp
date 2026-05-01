// Copyright Epic Games, Inc. All Rights Reserved.

#include "WanliGASMonitorUIManager.h"

FWanliGASMonitorUIManager& FWanliGASMonitorUIManager::Get()
{
	static FWanliGASMonitorUIManager Instance;
	return Instance;
}

void FWanliGASMonitorUIManager::PushEvent(const FWanliGASMonitorEvent& Event)
{
	OnEventReceived.Broadcast(Event);
}
