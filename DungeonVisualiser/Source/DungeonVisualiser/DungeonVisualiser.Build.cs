// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Cimpa : ModuleRules
{
	public Cimpa(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D", "ProceduralMeshComponent", "DungeonGenerator" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //PublicAdditionalLibraries.Add("DungeonGenerator/libraries/UnrealModulTest.lib");

        PublicIncludePaths.AddRange(
		new string[]{
			"Cimpa",
			"Cimpa/Enemies",
			"Cimpa/Player",
			"Cimpa/Projectiles",
			"Cimpa/Enemies/Interfaces",
			"Cimpa/Dungeon"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
