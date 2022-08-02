// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Examples/ASSCharacter_Example.h"

#include "_GPN_Character.generated.h"


class UGSActorComponent_PawnExtension;
class UISActorComponent_PawnExtension;
class UInputComponent;



/**
 * Game's base Character class
 */
UCLASS()
class A_GPN_Character : public AASSCharacter_Example
{
	GENERATED_BODY()


protected:
	UPROPERTY(VisibleAnywhere, Category = "GameSetup")
		TObjectPtr<UGSActorComponent_PawnExtension> GSPawnExtensionComponent;
	UPROPERTY(VisibleAnywhere, Category = "InputSetup")
		TObjectPtr<UISActorComponent_PawnExtension> ISPawnExtensionComponent;

public:
	A_GPN_Character(const FObjectInitializer& ObjectInitializer);

protected:
	//  BEGIN APawn interface
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	//  END APawn interface

};
