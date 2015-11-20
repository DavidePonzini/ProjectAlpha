// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECTALPHA_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	// Components
public:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		USpringArmComponent* SpringArmComp;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		UCameraComponent* CameraComp;

	// TO BE REMOVED
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | TEXT")
		UTextRenderComponent* text;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Movement
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	// Camera
	void Turn(float Value);
	void LookUp(float Value);

	// Jump
	void Jump();
};
