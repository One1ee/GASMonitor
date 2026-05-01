// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wanli_GASMonitorEditor : ModuleRules
{
	public Wanli_GASMonitorEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"Slate",
			"SlateCore",
			"EditorStyle",
			"GameplayAbilities",
			"GameplayTags",
			"Wanli_GASMonitor",
		});
	}
}
