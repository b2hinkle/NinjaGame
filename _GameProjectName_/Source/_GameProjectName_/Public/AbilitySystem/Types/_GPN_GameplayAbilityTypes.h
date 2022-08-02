// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Types/ASSGameplayAbilityTypes.h"

#include "_GPN_GameplayAbilityTypes.generated.h"


class A_GPN_Character;
class A_GPN_PlayerController;
class A_GPN_PlayerState;



/**
 * Game's base GameplayAbilityActorInfo.
 * Put non-game-specific data in here - like base classes and stuff.
 */
USTRUCT()
struct _GAMEPROJECTNAME__API F_GPN_GameplayAbilityActorInfo : public FASSGameplayAbilityActorInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "_GPN_ActorInfo")
        TWeakObjectPtr<A_GPN_Character> _GPN_Character;

    UPROPERTY(BlueprintReadOnly, Category = "_GPN_ActorInfo")
        TWeakObjectPtr<A_GPN_PlayerController> _GPN_PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "_GPN_ActorInfo")
        TWeakObjectPtr<A_GPN_PlayerState> _GPN_PlayerState;


    virtual void InitFromActor(AActor* OwnerActor, AActor* AvatarActor, UAbilitySystemComponent* InAbilitySystemComponent) override;
    virtual void ClearActorInfo() override;
};
