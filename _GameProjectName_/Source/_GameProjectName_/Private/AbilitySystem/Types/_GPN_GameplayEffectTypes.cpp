// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Types/_GPN_GameplayEffectTypes.h"



F_GPN_GameplayEffectContext::F_GPN_GameplayEffectContext()
{

}


bool F_GPN_GameplayEffectContext::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	return Super::NetSerialize(Ar, Map, bOutSuccess);
}
