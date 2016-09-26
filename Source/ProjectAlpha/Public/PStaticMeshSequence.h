// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PStaticMeshSequence.generated.h"

UCLASS()
class PROJECTALPHA_API APStaticMeshSequence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APStaticMeshSequence();

	// Called when changing properties in the editor
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	float MeshSize;

	float GetInstancedMeshSize() const;

public:
	UPROPERTY()
		UInstancedStaticMeshComponent* InstancedStaticMesh;

	UPROPERTY(EditAnywhere)
		USceneComponent* EndPoint;

	// Distance between spawned meshes
	UPROPERTY(EditAnywhere, Category = "StaticMeshSequence")
		float MeshOffset;

	UPROPERTY(EditAnywhere, Category = "StaticMeshSequence")
		UStaticMesh* Mesh;




	
};
