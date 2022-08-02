// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Types/_GPN_GameplayAbilityTypes.h"

#include "Character/_GPN_Character.h"
#include "Player/_GPN_PlayerController.h"
#include "Player/_GPN_PlayerState.h"



void F_GPN_GameplayAbilityActorInfo::InitFromActor(AActor* InOwnerActor, AActor* InAvatarActor, UAbilitySystemComponent* InAbilitySystemComponent)
{
	Super::InitFromActor(InOwnerActor, InAvatarActor, InAbilitySystemComponent);

	// Get our _GPN_Character
	_GPN_Character = Cast<A_GPN_Character>(InAvatarActor);

	// Get our PC and PS
	if (PlayerController.IsValid())
	{
		_GPN_PlayerController = Cast<A_GPN_PlayerController>(PlayerController.Get());
		_GPN_PlayerState = PlayerController->GetPlayerState<A_GPN_PlayerState>();
	}
	else
	{
		_GPN_PlayerController = nullptr;
		_GPN_PlayerState = nullptr;
	}
}

void F_GPN_GameplayAbilityActorInfo::ClearActorInfo()
{
	Super::ClearActorInfo();

	_GPN_Character = nullptr;
	_GPN_PlayerController = nullptr;
	_GPN_PlayerState = nullptr;
}
