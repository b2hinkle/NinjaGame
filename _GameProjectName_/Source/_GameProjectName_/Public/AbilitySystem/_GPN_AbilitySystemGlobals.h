// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/ASSAbilitySystemGlobals.h"

#include "_GPN_AbilitySystemGlobals.generated.h"



/**
 * Game's base AbilitySystemGlobals
 */
UCLASS()
class _GAMEPROJECTNAME__API U_GPN_AbilitySystemGlobals : public UASSAbilitySystemGlobals
{
	GENERATED_BODY()

public:
	U_GPN_AbilitySystemGlobals(const FObjectInitializer& ObjectInitializer);


	virtual FGameplayAbilityActorInfo* AllocAbilityActorInfo() const override;
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
};
