// Fill out your copyright notice in the Description page of Project Settings.


#include "Dungeon/ProceduralMesh.h"

// Sets default values for this component's properties
UProceduralMesh::UProceduralMesh()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>("ProcMesh");
}

void UProceduralMesh::AddVertices(TArray<FVector> vertices, TArray<int32> triangles)
{
	check(!created);

	Vertices = vertices;
	Triangles = triangles;

	UVs.Add(FVector2D(0, 0));
	UVs.Add(FVector2D(0, 1));
	UVs.Add(FVector2D(1, 0));
	UVs.Add(FVector2D(1, 1));
}

void UProceduralMesh::Create()
{
	check(!created);
	ProcMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), true);

	created = true;
}

void UProceduralMesh::SetMaterial(UMaterialInterface* Material)
{
	check(created);
	if (Material && created)
	{
		ProcMesh->SetMaterial(0, Material);
	}
}

// Called when the game starts
void UProceduralMesh::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProceduralMesh::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

