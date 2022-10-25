// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class _GameProjectName_ : ModuleRules
{
	public _GameProjectName_(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivatePCHHeaderFile = "Private/_GameProjectName_PrivatePCH.h";

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"GameCore",
				"GameSetup",
				"GameplayTags",
				"GameplayAbilities",
				"AbilitySystemSetup",
				"AbilitySystemSetupExtras",
				"EnhancedInput",
				"InputSetup",
				"AnimationSetup",
				"PawnSetup"
			}
		);
	}
}
