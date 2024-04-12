// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMesh.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONGENERATOR_API UProceduralMesh : public UActorComponent
{
	GENERATED_BODY()

private:
	TArray<FVector> Vertices; // a pontok
	TArray<int32> Triangles; // a haromszogek koruljarasi iranya fontos, az hatarozza meg a normal vektort
	TArray<FVector2D> UVs;  // texturahoz

	bool created = false;

public:
	UProceduralMeshComponent* ProcMesh;

public:	
	// Sets default values for this component's properties
	UProceduralMesh();

	void AddVertices(TArray<FVector> vertices, TArray<int32> triangles);
	void Create();
	void SetMaterial(UMaterialInterface* Material);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
