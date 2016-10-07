// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PGameState.h"



APGameState::APGameState()
{
	TimeScale = 60.0f;
}

void APGameState::SetTime(float NewTime)
{
	Time = NewTime;
}

void APGameState::IncrementTime(float Amount)
{
	Time += Amount * TimeScale;
}

void APGameState::SetTimeScale(float NewTimeScale)
{
	TimeScale = NewTimeScale;
}