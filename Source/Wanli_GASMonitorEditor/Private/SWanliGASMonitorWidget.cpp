// Copyright Epic Games, Inc. All Rights Reserved.

#include "SWanliGASMonitorWidget.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Styling/CoreStyle.h"
#include "GameplayTagContainer.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

void SWanliGASMonitorWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
		.Padding(FMargin(6.0f))
		.BorderBackgroundColor(FLinearColor(0.05f, 0.05f, 0.05f, 1.0f))
		[
			SNew(SVerticalBox)

			// Toolbar
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(0.0f, 0.0f, 0.0f, 4.0f))
			[
				SNew(SButton)
				.Text(FText::FromString(TEXT("Export Log")))
				.HAlign(HAlign_Center)
				.OnClicked(this, &SWanliGASMonitorWidget::OnExportClicked)
			]

			// Event list
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(ScrollBox, SScrollBox)
			]
		]
	];
}

void SWanliGASMonitorWidget::AddEvent(const FWanliGASMonitorEvent& Event)
{
	// Evict oldest entry when at capacity
	if (Events.Num() >= MaxEvents)
	{
		ScrollBox->RemoveSlot(EventWidgets[0]);
		Events.RemoveAt(0);
		EventWidgets.RemoveAt(0);
	}

	Events.Add(Event);

	// Build display text
	FString DisplayText;
	FLinearColor TextColor;

	const FString TimeStr = Event.Timestamp.ToString(TEXT("%H:%M:%S.%s"));

	if (Event.bSuccess)
	{
		DisplayText = FString::Printf(TEXT("[%s]  [%s]   SUCCESS"), *TimeStr, *Event.AbilityName);
		TextColor   = FLinearColor(0.2f, 0.9f, 0.2f, 1.0f); // green
	}
	else
	{
		const FString Reason = ParseFailureReason(Event.FailureTags);
		DisplayText = FString::Printf(TEXT("[%s]  [%s]   FAILED  →  %s"), *TimeStr, *Event.AbilityName, *Reason);
		TextColor   = FLinearColor(0.9f, 0.2f, 0.2f, 1.0f); // red
	}

	TSharedRef<STextBlock> EntryWidget =
		SNew(STextBlock)
		.Text(FText::FromString(DisplayText))
		.ColorAndOpacity(FSlateColor(TextColor))
		.Font(FCoreStyle::GetDefaultFontStyle("Mono", 10));

	EventWidgets.Add(EntryWidget);

	ScrollBox->AddSlot()
	.Padding(FMargin(2.0f, 1.0f))
	[
		EntryWidget
	];

	ScrollBox->ScrollToEnd();
}

FReply SWanliGASMonitorWidget::OnExportClicked()
{
	if (Events.IsEmpty())
		return FReply::Handled();

	// Ensure output directory exists
	const FString LogDir = FPaths::ProjectSavedDir() / TEXT("Wanli_GASMonitor_Log");
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!PlatformFile.DirectoryExists(*LogDir))
	{
		PlatformFile.CreateDirectoryTree(*LogDir);
	}

	// Filename: GASMonitor_YYYY-MM-DD_HH-MM-SS.txt
	const FString Timestamp = FDateTime::Now().ToString(TEXT("%Y-%m-%d_%H-%M-%S"));
	const FString FilePath = LogDir / FString::Printf(TEXT("GASMonitor_%s.txt"), *Timestamp);

	// Build file content
	FString Content;
	Content.Reserve(Events.Num() * 80);
	Content += FString::Printf(TEXT("Wanli GAS Monitor — Export %s\n"), *Timestamp);
	Content += TEXT("--------------------------------------------------------\n");
	for (const FWanliGASMonitorEvent& Event : Events)
	{
		Content += BuildLogLine(Event) + TEXT("\n");
	}

	FFileHelper::SaveStringToFile(Content, *FilePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);

	UE_LOG(LogTemp, Log, TEXT("WanliGASMonitor: Log exported to %s"), *FilePath);
	return FReply::Handled();
}

FString SWanliGASMonitorWidget::BuildLogLine(const FWanliGASMonitorEvent& Event) const
{
	const FString TimeStr = Event.Timestamp.ToString(TEXT("%H:%M:%S.%s"));
	if (Event.bSuccess)
	{
		return FString::Printf(TEXT("[%s]  [%s]   SUCCESS"), *TimeStr, *Event.AbilityName);
	}
	const FString Reason = ParseFailureReason(Event.FailureTags);
	return FString::Printf(TEXT("[%s]  [%s]   FAILED  ->  %s"), *TimeStr, *Event.AbilityName, *Reason);
}

FString SWanliGASMonitorWidget::ParseFailureReason(const FGameplayTagContainer& Tags) const
{
	if (Tags.IsEmpty())
		return TEXT("Unknown");

	// Check tag names by string — avoids asserting on missing registered tags
	TArray<FGameplayTag> TagArray;
	Tags.GetGameplayTagArray(TagArray);

	for (const FGameplayTag& TempTag : TagArray)
	{
		const FString TagName = TempTag.GetTagName().ToString();

		if (TagName.Contains(TEXT("Cooldown")))        return TEXT("Cooldown");
		if (TagName.Contains(TEXT("Cost")))             return TEXT("Cost");
		if (TagName.Contains(TEXT("BlockedByTags")))    return TEXT("Blocked");
		if (TagName.Contains(TEXT("MissingTags")))      return TEXT("Missing Tags");
		if (TagName.Contains(TEXT("TagsBlocked")))      return TEXT("Blocked");
		if (TagName.Contains(TEXT("Networking")))       return TEXT("Networking");
		if (TagName.Contains(TEXT("IsDead")))           return TEXT("Dead");
	}

	return Tags.ToStringSimple();
}
