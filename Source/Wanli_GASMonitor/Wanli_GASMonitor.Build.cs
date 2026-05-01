// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wanli_GASMonitor : ModuleRules
{
	public Wanli_GASMonitor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
		});
	}
}
