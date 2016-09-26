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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
		float fTime;
	UFUNCTION(exec)
		void SetTime(float Time);
	
	
};
