// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "WanliGASMonitorComponent.generated.h"

class UAbilitySystemComponent;
class UGameplayAbility;

/**
 * Attach to any Character (or Actor with an ASC) to monitor GAS ability
 * activations and failures in real time.
 */
UCLASS(ClassGroup=(GASMonitor), meta=(BlueprintSpawnableComponent))
class WANLI_GASMONITOR_API UWanliGASMonitorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWanliGASMonitorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GAS Monitor")
	bool bDisplayGASInfo = true;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void OnAbilityActivated(UGameplayAbility* Ability);
	void OnAbilityFailed(const UGameplayAbility* Ability, const FGameplayTagContainer& FailureTags);

	TWeakObjectPtr<UAbilitySystemComponent> CachedASC;
	FDelegateHandle ActivatedHandle;
	FDelegateHandle FailedHandle;
};
