// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Types/ASSGameplayAbilityTargetTypes.h"

#include "_GPN_GameplayAbilityTargetTypes.generated.h"



/**
 * Game's base GameplayAbilityTargetData
 */
USTRUCT()
struct _GAMEPROJECTNAME__API F_GPN_GameplayAbilityTargetData : public FASSGameplayAbilityTargetData
{
	GENERATED_BODY()

	F_GPN_GameplayAbilityTargetData();

	virtual UScriptStruct* GetScriptStruct() const override { return StaticStruct(); }
};
