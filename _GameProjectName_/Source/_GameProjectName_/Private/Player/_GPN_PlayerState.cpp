// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/_GPN_PlayerState.h"

#include "Subobjects/ActorComponents/GSActorComponent_PlayerStateExtension.h"



A_GPN_PlayerState::A_GPN_PlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GSPlayerStateExtensionComponent = CreateDefaultSubobject<UGSActorComponent_PlayerStateExtension>(TEXT("GSPlayerStateExtensionComponent"));
}
