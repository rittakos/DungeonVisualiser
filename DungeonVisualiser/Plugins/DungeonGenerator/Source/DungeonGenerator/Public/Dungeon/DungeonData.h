// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

//struct HoleData
//{
//	FVector		leftBottomCoord;
//	FVector2D	size;
//};

struct LayoutData
{
	TArray<FVector>	corners;
	TArray<int32>	triangles;
	//std::vector<HoleData>	holes;
};

struct WallData
{
	TArray<FVector>	corners;
	TArray<int32>	triangles;
	//std::optional<HoleData> door;
};

class DUNGEONGENERATOR_API DungeonData
{
private:
	std::vector<WallData> walls;
	std::vector<LayoutData> floors;

	unsigned int seed;
	int version;


public:
	DungeonData();
	DungeonData(const FString& filePath);
	~DungeonData();


	std::vector<LayoutData> GetFloors() const { return floors; }
	std::vector<WallData>	GetWalls()	const { return walls; }
	unsigned int			GetSeed()	const { return seed; }

	friend class DungeonReader;
};
