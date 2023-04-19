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
#include "ActorComponents/ASActorComponent_PortrayalAssignment.h"
#include "Portrayals/ASPortrayalDefinition_ViewerList.h"



A_GPN_Character::A_GPN_Character(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GSPawnExtensionComponent = CreateDefaultSubobject<UGSActorComponent_PawnExtension>(TEXT("GSPawnExtensionComponent"));
	ISPawnExtensionComponent = CreateDefaultSubobject<UISActorComponent_PawnExtension>(TEXT("ISPawnExtensionComponent"));
	PSPawnExtensionComponent = CreateDefaultSubobject<UPSActorComponent_PawnExtension>(TEXT("PSPawnExtensionComponent"));

	// Set up Character mesh
	UASBlueprintFunctionLibrary_SkeletalMeshComponentHelpers::ConfigureDefaultSkeletalMeshComponentTransform(GetMesh(), GetCapsuleComponent());

	SkinlessSkeletalMeshComponent = CreateDefaultSubobject<UASActorComponent_SkinlessSkeletalMesh>(TEXT("SkinlessSkeletalMeshComponent"));
	SkinlessSkeletalMeshComponent->SkeletalMeshComponentReference.ComponentProperty = TEXT("Mesh"); // NOTE: can't do GET_MEMBER_NAME_CHECKED() for the private member ACharacter::Mesh

	// Set up Skeletal Part Attacher
	AttachmentAttacherComponent = CreateDefaultSubobject<UASActorComponent_AttachmentAttacher>(TEXT("AttachmentAttacherComponent"));
	AttachmentAttacherComponent->AttacheeReference.ComponentProperty = TEXT("Mesh");

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	UCSBlueprintFunctionLibrary_CameraComponentHelpers::ConfigureDefaultCameraComponentTransform(CameraComponent, this);
	CameraComponent->bUsePawnControlRotation = true;
}

void A_GPN_Character::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	AttachmentAttacherComponent->SpawnAttachments();

	// Add us to the first person portrayals' view actor lists.
	// This is assuming that we are in first person.
	for (const AActor* Attachment : AttachmentAttacherComponent->GetAttachments())
	{
		UASActorComponent_PortrayalAssignment* PortrayalAssignmentComponent = Attachment->FindComponentByClass<UASActorComponent_PortrayalAssignment>();
		if (IsValid(PortrayalAssignmentComponent))
		{
			UASPortrayalDefinition* PortrayalDefinition = PortrayalAssignmentComponent->GetInstancedPortrayalDefinition(_GPN_NativeGameplayTags::Portrayal_FirstPerson);
			UASPortrayalDefinition_ViewerList* FirstPersonPortrayalDefinitionInstance = Cast<UASPortrayalDefinition_ViewerList>(PortrayalDefinition);
			if (IsValid(FirstPersonPortrayalDefinitionInstance))
			{
				PortrayalAssignmentComponent->UnapplyPortrayals();

				if (IsValid(FirstPersonPortrayalDefinitionInstance))
				{
					FirstPersonPortrayalDefinitionInstance->ActorList.Add(this);
				}

				PortrayalAssignmentComponent->ApplyPortrayals();
			}
		}
	}
}


void A_GPN_Character::PawnClientRestart()
{
	Super::PawnClientRestart();

	ISPawnExtensionComponent->OnOwnerPawnClientRestart();
}

void A_GPN_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PSPawnExtensionComponent->OnOwnerSetupPlayerInputComponent(PlayerInputComponent);
}
