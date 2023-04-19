// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Portrayals/ASPortrayalDefinition_ViewerList.h"

#include "_GPN_PortrayalDefinition_FirstPerson.generated.h"



/**
 * Portrayal for showing first-person-portrayed components to viewers who want to see it.
 */
UCLASS()
class _GAMEPROJECTNAME__API U_GPN_PortrayalDefinition_FirstPerson : public UASPortrayalDefinition_ViewerList
{
	GENERATED_BODY()

public:
	U_GPN_PortrayalDefinition_FirstPerson();
};
