// Copyright Epic Games, Inc. All Rights Reserved.

#include "WanliGASMonitorComponent.h"
#include "WanliGASMonitorUIManager.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Abilities/GameplayAbility.h"

UWanliGASMonitorComponent::UWanliGASMonitorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWanliGASMonitorComponent::BeginPlay()
{
	Super::BeginPlay();

	UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(GetOwner());
	if (!ASC)
	{
		UE_LOG(LogTemp, Warning, TEXT("WanliGASMonitor: No AbilitySystemComponent found on %s"), *GetOwner()->GetName());
		return;
	}

	CachedASC = ASC;

	ActivatedHandle = ASC->AbilityActivatedCallbacks.AddUObject(
		this, &UWanliGASMonitorComponent::OnAbilityActivated);

	FailedHandle = ASC->AbilityFailedCallbacks.AddUObject(
		this, &UWanliGASMonitorComponent::OnAbilityFailed);
}

void UWanliGASMonitorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (CachedASC.IsValid())
	{
		CachedASC->AbilityActivatedCallbacks.Remove(ActivatedHandle);
		CachedASC->AbilityFailedCallbacks.Remove(FailedHandle);
	}
	Super::EndPlay(EndPlayReason);
}

void UWanliGASMonitorComponent::OnAbilityActivated(UGameplayAbility* Ability)
{
	if (!bDisplayGASInfo || !Ability)
		return;

	FWanliGASMonitorEvent Event;
	Event.AbilityName = Ability->GetName();
	Event.bSuccess = true;
	Event.Timestamp = FDateTime::Now();

	UE_LOG(LogTemp, Log, TEXT("WanliGASMonitor: [%s] ACTIVATED"), *Event.AbilityName);
	FWanliGASMonitorUIManager::Get().PushEvent(Event);
}

void UWanliGASMonitorComponent::OnAbilityFailed(const UGameplayAbility* Ability, const FGameplayTagContainer& FailureTags)
{
	if (!bDisplayGASInfo || !Ability)
		return;

	FWanliGASMonitorEvent Event;
	Event.AbilityName = Ability->GetName();
	Event.bSuccess = false;
	Event.FailureTags = FailureTags;
	Event.Timestamp = FDateTime::Now();

	UE_LOG(LogTemp, Warning, TEXT("WanliGASMonitor: [%s] FAILED  Tags: %s"),
		*Event.AbilityName, *FailureTags.ToStringSimple());

	FWanliGASMonitorUIManager::Get().PushEvent(Event);
}
