// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DungeonGenerator : ModuleRules
{
	public DungeonGenerator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				"$(PluginDir)\\includes\\Base",
				"$(PluginDir)\\includes\\Data",
				"$(PluginDir)\\includes\\DungeonGenerator",
				"$(PluginDir)\\includes\\Generator",
				"$(PluginDir)\\includes\\Geometry",
				"$(PluginDir)\\includes\\Math",
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "ProceduralMeshComponent",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        PublicAdditionalLibraries.AddRange(
            new string[]
            {
                "$(PluginDir)\\libraries\\Base.lib",
                "$(PluginDir)\\libraries\\Data.lib",
                "$(PluginDir)\\libraries\\DungeonGenerator.lib",
                "$(PluginDir)\\libraries\\Generator.lib",
                "$(PluginDir)\\libraries\\Geometry.lib",
                "$(PluginDir)\\libraries\\Math.lib"
            }
			);
    }
}
