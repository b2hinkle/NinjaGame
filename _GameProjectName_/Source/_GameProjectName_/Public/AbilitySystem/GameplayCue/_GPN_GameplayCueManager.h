// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayCue/ASSGameplayCueManager.h"

#include "_GPN_GameplayCueManager.generated.h"



/**
 * Our custom GameplayCueManager
 */
UCLASS()
class _GAMEPROJECTNAME__API U_GPN_GameplayCueManager : public UASSGameplayCueManager
{
	GENERATED_BODY()

public:
	virtual void FlushPendingCues() override;

};
