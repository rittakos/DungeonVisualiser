// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonData.h"

/**
*
*/

enum BlockType { Unknown, Header, Wall, Floor, Room, End };

struct BlockData
{
	BlockType type;
	int blockSize; // lines
};


class DUNGEONGENERATOR_API DungeonReader
{
private:
	TArray<FString> inputLines;
	int lineIdx;

	DungeonData dungeonData;
public:
	DungeonReader() = delete;
	DungeonReader(const FString& filePath);
	~DungeonReader();

	DungeonData getDungeonData() const { return dungeonData; }

private:
	WallData readWallBlock();
	LayoutData readFloorBlock();

private:

	static FVector lineToVector(const FString& line);
	static BlockData lineToBlock(const FString& line);
};