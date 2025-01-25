// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bubble_Wand : ModuleRules
{
	public Bubble_Wand(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
