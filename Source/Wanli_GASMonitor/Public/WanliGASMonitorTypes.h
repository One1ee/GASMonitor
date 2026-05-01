// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FWanliGASMonitorEvent
{
	FString AbilityName;
	bool bSuccess = false;
	FGameplayTagContainer FailureTags;
	FDateTime Timestamp;
};
