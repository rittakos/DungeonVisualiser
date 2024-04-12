// Fill out your copyright notice in the Description page of Project Settings.


#include "Dungeon/Floor.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	procMesh = CreateDefaultSubobject<UProceduralMesh>(TEXT("ProceduralMesh"));
	RootComponent = procMesh->ProcMesh;
}

void AFloor::Init(const LayoutData& floorData, UMaterialInterface* Material)
{
	Vertices = floorData.corners;
	Triangles = floorData.triangles;

	procMesh->AddVertices(Vertices, Triangles);
	procMesh->Create();
	procMesh->SetMaterial(Material);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

