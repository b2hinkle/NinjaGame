// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/_GPN_GameMode.h"

#include "Game/_GPN_GameState.h"
#include "Player/_GPN_PlayerController.h"
#include "Player/_GPN_PlayerState.h"
#include "UI/_GPN_HUD.h"
#include "Character/_GPN_Character.h"



A_GPN_GameMode::A_GPN_GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GameStateClass = A_GPN_GameState::StaticClass();
	PlayerControllerClass = A_GPN_PlayerController::StaticClass();
	PlayerStateClass = A_GPN_PlayerState::StaticClass();
	HUDClass = A_GPN_HUD::StaticClass();
	DefaultPawnClass = A_GPN_Character::StaticClass();
	ReplaySpectatorPlayerControllerClass = A_GPN_PlayerController::StaticClass();
}
