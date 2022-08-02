// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/_GPN_AbilitySystemGlobals.h"

#include "AbilitySystem/Types/_GPN_GameplayAbilityTypes.h"
#include "AbilitySystem/Types/_GPN_GameplayEffectTypes.h"



U_GPN_AbilitySystemGlobals::U_GPN_AbilitySystemGlobals(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


FGameplayAbilityActorInfo* U_GPN_AbilitySystemGlobals::AllocAbilityActorInfo() const
{
	return new F_GPN_GameplayAbilityActorInfo();
}
FGameplayEffectContext* U_GPN_AbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new F_GPN_GameplayEffectContext();
}
