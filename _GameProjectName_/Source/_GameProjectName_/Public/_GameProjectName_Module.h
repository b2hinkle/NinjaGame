// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//#include "_GameProjectName_Module.generated.h" // uncomment this if we need reflection in here



/**
 * _Game Project Name_ primary game module
 */
class F_GameProjectName_Module : public FDefaultGameModuleImpl
{
protected:
	//  BEGIN IModuleInterface interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//  END IModuleInterface interface
};
