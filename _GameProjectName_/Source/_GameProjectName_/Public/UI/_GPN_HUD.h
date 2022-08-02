// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "_GPN_HUD.generated.h"



/**
 * Game's base HUD class
 */
UCLASS()
class _GAMEPROJECTNAME__API A_GPN_HUD : public AHUD
{
	GENERATED_BODY()

public:
	A_GPN_HUD(const FObjectInitializer& ObjectInitializer);

};
