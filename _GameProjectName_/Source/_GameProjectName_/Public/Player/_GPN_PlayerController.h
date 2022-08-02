// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "_GPN_PlayerController.generated.h"



/**
 * Game's base PlayerController class
 */
UCLASS()
class _GAMEPROJECTNAME__API A_GPN_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	A_GPN_PlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	//  BEGIN AController Interface
	virtual void InitPlayerState() override;
	virtual void OnRep_PlayerState() override;
	//  END AController Interface
};
