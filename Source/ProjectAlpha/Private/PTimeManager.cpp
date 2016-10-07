// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PTimeManager.h"


// Sets default values
APTimeManager::APTimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APTimeManager::BeginPlay()
{
	Super::BeginPlay();

	GameState = GetWorld()->GetGameState<APGameState>();

	// NEEDS TESTING!!!
//	if (!GameState)
//		Destroy();

}

// Called every frame
void APTimeManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	GameState->IncrementTime(DeltaTime);

	const FRotator SunRotation = TimeToRotation(GameState->Time);
	RotateSun(SunRotation);
}

FRotator APTimeManager::TimeToRotation(float Time) const
{
	// Degrees in a full rotation / seconds per day
	const float SecondsPerDay = 60 * 60 * 24;
	const float ConversionMult = 360 / SecondsPerDay;

	const float RotationAmount = Time * ConversionMult;

	FRotator Rotation;
	Rotation.Pitch = RotationAmount;

	Rotation += RotationOffset;

	return Rotation;
}