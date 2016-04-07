// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "EquippableActor.h"


// Sets default values
AEquippableActor::AEquippableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEquippableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquippableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

