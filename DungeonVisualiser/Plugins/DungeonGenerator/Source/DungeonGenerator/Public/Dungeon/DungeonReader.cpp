// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonReader.h"

DungeonReader::DungeonReader(const FString& filePath) : lineIdx(0)
{
	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	FString FileContent;
	// Always first check if the file that you want to manipulate exist.
	if (FileManager.FileExists(*filePath))
	{
		// We use the LoadFileToString to load the file into
		FFileHelper::LoadFileToString(FileContent, *filePath, FFileHelper::EHashOptions::None);
	}
	const TCHAR* endOfLine = TEXT("\r\n");
	FileContent.ParseIntoArray(inputLines, endOfLine, true);

	dungeonData.version = FCString::Atoi(ToCStr(inputLines[lineIdx++]));
	dungeonData.seed = FCString::Atoi(ToCStr(inputLines[lineIdx++]));

	bool end = false;

	while (!end)
	{
		BlockData currentBlock = lineToBlock(inputLines[lineIdx++]);

		if (currentBlock.type == BlockType::Floor)
			readFloorBlock();
		else if (currentBlock.type == BlockType::Wall)
			readWallBlock();
		else if (currentBlock.type == BlockType::End)
			end = true;
	}


}

FVector DungeonReader::lineToVector(const FString& line)
{
	TArray<FString> lineParts;

	line.ParseIntoArray(lineParts, TEXT(" "), true);

	check(lineParts.Num() == 3);

	float x = FCString::Atof(ToCStr(lineParts[0]));
	float y = FCString::Atof(ToCStr(lineParts[1]));
	float z = FCString::Atof(ToCStr(lineParts[2]));

	return FVector(x, y, z);
}

WallData DungeonReader::readWallBlock()
{
	WallData wall;

	TArray<FString> sizeParts;
	inputLines[lineIdx++].ParseIntoArray(sizeParts, TEXT(" "), true);

	check(sizeParts.Num() == 2);

	int verticesCount = FCString::Atoi(ToCStr(sizeParts[0]));
	int triangleCount = FCString::Atoi(ToCStr(sizeParts[1]));

	for (int idx = 0; idx < verticesCount; ++idx)
	{
		FVector P = DungeonReader::lineToVector(inputLines[lineIdx++]);
		wall.corners.Add(P);
	}

	for (int idx = 0; idx < triangleCount; ++idx)
	{
		TArray<FString> triangleParts;

		inputLines[lineIdx++].ParseIntoArray(triangleParts, TEXT(" "), true);

		check(triangleParts.Num() == 3);

		wall.triangles.Add(FCString::Atoi(ToCStr(triangleParts[0])));
		wall.triangles.Add(FCString::Atoi(ToCStr(triangleParts[1])));
		wall.triangles.Add(FCString::Atoi(ToCStr(triangleParts[2])));
	}

	dungeonData.walls.push_back(wall);

	return wall;
}

LayoutData DungeonReader::readFloorBlock()
{
	LayoutData floor;

	TArray<FString> sizeParts;
	inputLines[lineIdx++].ParseIntoArray(sizeParts, TEXT(" "), true);

	check(sizeParts.Num() == 2);

	int verticesCount = FCString::Atoi(ToCStr(sizeParts[0]));
	int triangleCount = FCString::Atoi(ToCStr(sizeParts[1]));

	for (int idx = 0; idx < verticesCount; ++idx)
	{
		FVector P = DungeonReader::lineToVector(inputLines[lineIdx++]);
		floor.corners.Add(P);
	}

	for (int idx = 0; idx < triangleCount; ++idx)
	{
		TArray<FString> triangleParts;

		inputLines[lineIdx++].ParseIntoArray(triangleParts, TEXT(" "), true);

		check(triangleParts.Num() == 3);

		floor.triangles.Add(FCString::Atoi(ToCStr(triangleParts[0])));
		floor.triangles.Add(FCString::Atoi(ToCStr(triangleParts[1])));
		floor.triangles.Add(FCString::Atoi(ToCStr(triangleParts[2])));
	}

	dungeonData.floors.push_back(floor);

	return floor;
}

BlockData DungeonReader::lineToBlock(const FString& line)
{
	BlockData data;
	data.type = BlockType::Unknown;

	TArray<FString> lineParts;

	line.ParseIntoArray(lineParts, TEXT(" "), true);

	check(lineParts.Num() == 1);

	if (line == "Floor")
		data.type = BlockType::Floor;
	else if (line == "Wall")
		data.type = BlockType::Wall;
	else if (line == "End")
	{
		data.type = BlockType::End;
		return data;
	}

	return data;
}

DungeonReader::~DungeonReader()
{
}
