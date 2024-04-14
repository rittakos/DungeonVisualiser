// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DungeonData.h"
#include "ProceduralMesh.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class DUNGEONGENERATOR_API AWall : public AActor
{
	GENERATED_BODY()

private:
	UProceduralMesh* procMesh;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
public:	
	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Init(const WallData& wallData, UMaterialInterface* Material = nullptr);
};
