// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PGameState.h"
#include "PTimeManager.generated.h"

UCLASS()
class PROJECTALPHA_API APTimeManager : public AActor
{
	GENERATED_BODY()
private:
	APGameState* GameState;

	FRotator TimeToRotation(float Time) const;

public:	
	// Sets default values for this actor's properties
	APTimeManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Time")
		void RotateSun(FRotator SunRotation);

	UPROPERTY(EditAnywhere, Category = "Time")
		FRotator RotationOffset;
	
};
