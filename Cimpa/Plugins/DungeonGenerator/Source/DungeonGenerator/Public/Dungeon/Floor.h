// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMesh.h"
#include "DungeonData.h"
#include "Floor.generated.h"

UCLASS()
class DUNGEONGENERATOR_API AFloor : public AActor
{
	GENERATED_BODY()
private:
	UProceduralMesh* procMesh;

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
public:	
	// Sets default values for this actor's properties
	AFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Init(const LayoutData& floorData, UMaterialInterface* Material = nullptr);

};
