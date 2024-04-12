// Fill out your copyright notice in the Description page of Project Settings.


#include "Dungeon/Wall.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	procMesh = CreateDefaultSubobject<UProceduralMesh>(TEXT("ProceduralMesh"));
	RootComponent = procMesh->ProcMesh;
}

void AWall::Init(const WallData& wallData, UMaterialInterface* Material)
{
	Vertices = wallData.corners;
	Triangles = wallData.triangles;

	procMesh->AddVertices(Vertices, Triangles);
	procMesh->Create();
	procMesh->SetMaterial(Material);
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

