// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/_GPN_Character.h"

#include "Subobjects/ActorComponents/GSActorComponent_PawnExtension.h"
#include "ActorComponents/ISActorComponent_PawnExtension.h"
#include "ActorComponents/ASActorComponent_SkinlessSkeletalMesh.h"
#include "ActorComponents/ASActorComponent_AttachmentAttacher.h"
#include "BlueprintFunctionLibraries/ASBlueprintFunctionLibrary_SkeletalMeshComponentHelpers.h"
#include "ActorComponents/PSActorComponent_PawnExtension.h"
#include "Camera/CameraComponent.h"
#include "BlueprintFunctionLibraries/CSBlueprintFunctionLibrary_CameraComponentHelpers.h"



A_GPN_Character::A_GPN_Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GSPawnExtensionComponent = CreateDefaultSubobject<UGSActorComponent_PawnExtension>(TEXT("GSPawnExtensionComponent"));
	ISPawnExtensionComponent = CreateDefaultSubobject<UISActorComponent_PawnExtension>(TEXT("ISPawnExtensionComponent"));
	PSPawnExtensionComponent = CreateDefaultSubobject<UPSActorComponent_PawnExtension>(TEXT("PSPawnExtensionComponent"));

	// Set up Character mesh
	UASBlueprintFunctionLibrary_SkeletalMeshComponentHelpers::ConfigureDefaultSkeletalMeshComponentTransform(GetMesh(), GetCapsuleComponent());

	SkinlessSkeletalMeshComponent = CreateDefaultSubobject<UASActorComponent_SkinlessSkeletalMesh>(TEXT("SkinlessSkeletalMeshComponent"));
	SkinlessSkeletalMeshComponent->UseSkeletalMeshComponent(GetMesh());

	// Set up Skeletal Part Attacher
	AttachmentAttacherComponent = CreateDefaultSubobject<UASActorComponent_AttachmentAttacher>(TEXT("AttachmentAttacherComponent"));
	AttachmentAttacherComponent->SetAttachee(GetMesh());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	UCSBlueprintFunctionLibrary_CameraComponentHelpers::ConfigureDefaultCameraComponentTransform(CameraComponent, this);
	CameraComponent->bUsePawnControlRotation = true;
}

void A_GPN_Character::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	AttachmentAttacherComponent->SpawnAttachments();
}


void A_GPN_Character::PawnClientRestart()
{
	Super::PawnClientRestart();

	ISPawnExtensionComponent->OnOwnerPawnClientRestart();
}

void A_GPN_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	ISPawnExtensionComponent->OnOwnerSetupPlayerInputComponent(PlayerInputComponent);
	PSPawnExtensionComponent->OnOwnerSetupPlayerInputComponent(PlayerInputComponent);
}
