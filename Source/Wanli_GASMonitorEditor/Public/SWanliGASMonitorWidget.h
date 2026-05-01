// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "WanliGASMonitorTypes.h"

class SScrollBox;

/**
 * Slate widget that displays a live scrollable log of GAS ability events.
 * Created and owned by the Editor module; receives events via AddEvent().
 */
class SWanliGASMonitorWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SWanliGASMonitorWidget) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void AddEvent(const FWanliGASMonitorEvent& Event);

private:
	FReply OnExportClicked();
	FString BuildLogLine(const FWanliGASMonitorEvent& Event) const;
	FString ParseFailureReason(const FGameplayTagContainer& Tags) const;

	TSharedPtr<SScrollBox> ScrollBox;

	// Parallel arrays: one event struct, one widget reference for O(1) removal
	TArray<FWanliGASMonitorEvent> Events;
	TArray<TSharedRef<SWidget>> EventWidgets;

	static constexpr int32 MaxEvents = 100;
};
