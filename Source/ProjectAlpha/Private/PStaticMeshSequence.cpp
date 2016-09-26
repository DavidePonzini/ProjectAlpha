// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PStaticMeshSequence.h"


// Sets default values
APStaticMeshSequence::APStaticMeshSequence()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InstancedStaticMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Instaced Static Mesh"));
	
	EndPoint = CreateDefaultSubobject<USceneComponent>(TEXT("End Point"));
	EndPoint->AttachToComponent(InstancedStaticMesh, FAttachmentTransformRules::SnapToTargetIncludingScale);

}


void APStaticMeshSequence::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	MeshSize = (Mesh) ? Mesh->GetBoundingBox().GetSize().X : 0.0f;
	MeshOffset = FMath::Clamp(MeshOffset, 0.0f, MeshOffset);

	InstancedStaticMesh->SetStaticMesh(Mesh);

	const float EndDistance = EndPoint->GetRelativeTransform().GetLocation().X;

	LOG_ACTOR(Log, this, "InstancedMeshSize: %f", GetInstancedMeshSize());

	while (EndDistance > GetInstancedMeshSize())
	{
		const FVector InstanceLocation = FVector(GetInstancedMeshSize(), 0.0f, 0.0f);
		const FRotator InstanceRotation = FRotator();
		const FVector InstanceScale = FVector();

		const FTransform InstanceTransform = FTransform(InstanceRotation, InstanceLocation, InstanceScale);

		LOG_ACTOR(Log, this, "Adding instance");
		InstancedStaticMesh->AddInstance(InstanceTransform);
	}
}

float APStaticMeshSequence::GetInstancedMeshSize() const
{
	return (MeshSize + MeshOffset) * InstancedStaticMesh->GetInstanceCount();
}