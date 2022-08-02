// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/GSGameInstance.h"

#include "_GPN_GameInstance.generated.h"



/**
 * Game's base GameInstance class
 */
UCLASS()
class _GAMEPROJECTNAME__API U_GPN_GameInstance : public UGSGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

};
