// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class DungeonGeneration : uint8 {
	Voronoi,
	Delaunay,
	None
};
