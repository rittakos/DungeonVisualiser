// Fill out your copyright notice in the Description page of Project Settings.


#include "Dungeon/Dungeon.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Dungeon/DungeonReader.h"

//#include <Generator/dungeonGenereatorSettings.hpp>
//#include "random.h"
//#include "DungeonGenerator/dungeon.hpp"
//#include <Generator/mazeGeneratorSettings.hpp>
//#include <Generator/holeGeneratorSettings.hpp>

// Sets default values
ADungeon::ADungeon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADungeon::BeginPlay()
{
	Super::BeginPlay();
	
	Generate();
	SpawnParts();


}

// Called every frame
void ADungeon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADungeon::SpawnParts()
{
	FActorSpawnParameters SpawnInfo;

	FRotator myRot(0, 0, 0);
	FVector myLoc(0, 0, 0);

	//AFloor* floor = GetWorld()->SpawnActor<AFloor>(AFloor::StaticClass(), myLoc, myRot, SpawnInfo);
	DungeonReader reader(Path);
	DungeonData data = reader.getDungeonData();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, (FString::FromInt(data.GetSeed())));

	UWorld* World = GetWorld();
	const FTransform SpawnLocAndRotation;

	for (const LayoutData& floor : data.GetFloors())
	{
		AFloor* newFloor = World->SpawnActorDeferred<AFloor>(AFloor::StaticClass(), SpawnLocAndRotation);
		newFloor->Init(floor, FloorMaterial);
		newFloor->FinishSpawning(SpawnLocAndRotation);
		floors.Add(newFloor);
	}


	for (const WallData& wall : data.GetWalls())
	{
		AWall* newWall = World->SpawnActorDeferred<AWall>(AWall::StaticClass(), SpawnLocAndRotation);
		newWall->Init(wall, WallMaterial);
		newWall->FinishSpawning(SpawnLocAndRotation);
		walls.Add(newWall);
	}
}

void ADungeon::Redraw()
{
	for (AWall* wall : walls)
		wall->Destroy();
}

void ADungeon::Generate()
{
	//Random::Seed seed(10);

	/*DungeonGeneratorSettings generatorSettings(GeneratorAlgorithmType::Delaunay, seed, 10);
	MazeGeneratorSettings mazeGeneratorSettings(MazeGeneratorType::Kruskal, seed);
	HoleGeneratorSettings holeGeneratorSettings(HoleGeneratorType::Basic, seed);

	Random::SetSeed(generatorSettings.getSeed());

	Dungeon dungeon;
	dungeon.generateDungeon(generatorSettings);
	dungeon.generateMaze(mazeGeneratorSettings);
	dungeon.generateHoles(holeGeneratorSettings);

	dungeon.save(Path);*/
}

