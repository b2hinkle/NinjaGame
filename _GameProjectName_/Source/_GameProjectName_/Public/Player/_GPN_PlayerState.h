// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/ASSEPlayerState_AbilitySystemPlayerState.h"

#include "_GPN_PlayerState.generated.h"


class UGSActorComponent_PlayerStateExtension;



/**
 * Game's base PlayerState class
 */
UCLASS()
class _GAMEPROJECTNAME__API A_GPN_PlayerState : public AASSEPlayerState_AbilitySystemPlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		TObjectPtr<UGSActorComponent_PlayerStateExtension> GSPlayerStateExtensionComponent;

public:
	A_GPN_PlayerState(const FObjectInitializer& ObjectInitializer);

};
