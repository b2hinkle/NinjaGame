// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/GSGameMode.h"

#include "_GPN_GameMode.generated.h"



/**
 * Game's base GameMode class
 */
UCLASS()
class _GAMEPROJECTNAME__API A_GPN_GameMode : public AGSGameMode
{
	GENERATED_BODY()

public:
	A_GPN_GameMode(const FObjectInitializer& ObjectInitializer);

protected:

};
