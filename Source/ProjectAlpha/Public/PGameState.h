// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "PGameState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTALPHA_API APGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	APGameState();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
		float Time;
	
	UFUNCTION(exec)
		void SetTime(float NewTime);

	UFUNCTION(exec, BlueprintCallable, Category = "Time")
		void IncrementTime(float Amount);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Time")
		float TimeScale;

	UFUNCTION(exec)
		void SetTimeScale(float NewTimeScale);
};
