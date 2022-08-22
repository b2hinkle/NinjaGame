// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/_GPN_Character.h"

#include "Subobjects/ActorComponents/GSActorComponent_PawnExtension.h"
#include "ActorComponents/ISActorComponent_PawnExtension.h"
#include "ActorComponents/ASActorComponent_PartAttacher.h"
#include "Mesh/ASBlueprintFunctionLibrary_SkeletalMeshHelpers.h"



A_GPN_Character::A_GPN_Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GSPawnExtensionComponent = CreateDefaultSubobject<UGSActorComponent_PawnExtension>(TEXT("GSPawnExtensionComponent"));
	ISPawnExtensionComponent = CreateDefaultSubobject<UISActorComponent_PawnExtension>(TEXT("ISPawnExtensionComponent"));
	PartAttacherComponent = CreateDefaultSubobject<UASActorComponent_PartAttacher>(TEXT("PartAttacherComponent"));

	UASBlueprintFunctionLibrary_SkeletalMeshHelpers::SetupDefaultMeshTransform(GetMesh(), GetCapsuleComponent());
}


void A_GPN_Character::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	PartAttacherComponent->InitializeWithMeshComponent(GetMesh());
}

void A_GPN_Character::PawnClientRestart()
{
	Super::PawnClientRestart();

	ISPawnExtensionComponent->PawnClientRestart();
}

void A_GPN_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ISPawnExtensionComponent->SetupPlayerInputComponent(PlayerInputComponent);
}
