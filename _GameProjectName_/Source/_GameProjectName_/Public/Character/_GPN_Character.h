// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Examples/ASSCharacter_Example.h"

#include "_GPN_Character.generated.h"


class UGSActorComponent_PawnExtension;
class UISActorComponent_PawnExtension;
class UASActorComponent_SkinlessSkeletalMesh;
class UASActorComponent_AttachmentAttacher;
class UInputComponent;
class UPSActorComponent_PawnExtension;
class UCameraComponent;



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
	UPROPERTY(VisibleAnywhere, Category = "PawnSetup")
		TObjectPtr<UPSActorComponent_PawnExtension> PSPawnExtensionComponent;
	UPROPERTY(VisibleAnywhere, Category = "AnimationSetup")
		TObjectPtr<UASActorComponent_SkinlessSkeletalMesh> SkinlessSkeletalMeshComponent;
	UPROPERTY(VisibleAnywhere, Category = "AnimationSetup")
		TObjectPtr<UASActorComponent_AttachmentAttacher> AttachmentAttacherComponent;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
		TObjectPtr<UCameraComponent> CameraComponent;

public:
	A_GPN_Character(const FObjectInitializer& ObjectInitializer);


protected:
	//  BEGIN AActor interface
	virtual void PostRegisterAllComponents() override;
	//  END AActor interface

	//  BEGIN APawn interface
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	//  END APawn interface
};
