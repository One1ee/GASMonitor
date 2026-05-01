// Copyright Epic Games, Inc. All Rights Reserved.

#include "Wanli_GASMonitorEditor.h"
#include "SWanliGASMonitorWidget.h"
#include "WanliGASMonitorUIManager.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SWindow.h"

#define LOCTEXT_NAMESPACE "FWanli_GASMonitorEditorModule"

void FWanli_GASMonitorEditorModule::StartupModule()
{
	// Subscribe to runtime events; window is created lazily on first event
	EventHandle = FWanliGASMonitorUIManager::Get().OnEventReceived.AddRaw(
		this, &FWanli_GASMonitorEditorModule::OnGASMonitorEvent);
}

void FWanli_GASMonitorEditorModule::ShutdownModule()
{
	FWanliGASMonitorUIManager::Get().OnEventReceived.Remove(EventHandle);

	if (MonitorWindow.IsValid())
	{
		MonitorWindow->RequestDestroyWindow();
		MonitorWindow.Reset();
	}
}

void FWanli_GASMonitorEditorModule::EnsureWindowCreated()
{
	if (MonitorWindow.IsValid())
		return;

	if (!FSlateApplication::IsInitialized())
		return;

	SAssignNew(MonitorWidget, SWanliGASMonitorWidget);

	MonitorWindow = SNew(SWindow)
		.Title(LOCTEXT("WindowTitle", "Wanli GAS Monitor"))
		.ClientSize(FVector2D(480.0f, 600.0f))
		.SizingRule(ESizingRule::UserSized)
		.SupportsMaximize(true)
		.SupportsMinimize(true)
		[
			MonitorWidget.ToSharedRef()
		];

	// Bind to close so we can clear the pointer
	MonitorWindow->SetOnWindowClosed(FOnWindowClosed::CreateLambda(
		[this](const TSharedRef<SWindow>&)
		{
			MonitorWindow.Reset();
			MonitorWidget.Reset();
		}));

	FSlateApplication::Get().AddWindow(MonitorWindow.ToSharedRef());
}

void FWanli_GASMonitorEditorModule::OnGASMonitorEvent(const FWanliGASMonitorEvent& Event)
{
	EnsureWindowCreated();

	if (MonitorWidget.IsValid())
	{
		MonitorWidget->AddEvent(Event);
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FWanli_GASMonitorEditorModule, Wanli_GASMonitorEditor)
