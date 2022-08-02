// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/_GPN_PlayerController.h"



A_GPN_PlayerController::A_GPN_PlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


void A_GPN_PlayerController::InitPlayerState()
{
	Super::InitPlayerState();
	// Right after Player State gets created
}
void A_GPN_PlayerController::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Right after Player State gets repped
}
