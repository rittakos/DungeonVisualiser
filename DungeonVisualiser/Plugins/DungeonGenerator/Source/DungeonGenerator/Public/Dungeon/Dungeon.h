// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DungeonGeneratorEnums.h"

#include "Floor.h"
#include "Wall.h"
#include "DungeonData.h"

#include "Dungeon.generated.h"

UCLASS()
class DUNGEONGENERATOR_API ADungeon : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UMaterialInterface* WallMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* FloorMaterial;

	UPROPERTY(EditAnywhere)
	bool wallsVisible;

	UPROPERTY(EditAnywhere)
	float wallWidth;

	UPROPERTY(EditAnywhere)
	FString Path = TEXT("C:/Projects/DungeonGenerator/dungeon.dg");

private:
	DungeonData dungeonData;

	TArray<AFloor*> floors;
	TArray<AWall*> walls;

public:
	UPROPERTY(EditAnywhere)
	DungeonGeneration generationType;

private:
	void SpawnParts();
	void Redraw();
	void Generate();

public:	
	// Sets default values for this actor's properties
	ADungeon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
