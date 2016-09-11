// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PCharacter.h"
#include "PInteractableComponent.h"
#include "PPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTALPHA_API APPlayerCharacter : public APCharacter
{
	GENERATED_BODY()
	
/***** COMPONENTS *****/
public:
	// Camera components
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		UCameraComponent* Camera;

public:
	/** Sets default values for this character's properties */
	APPlayerCharacter();

	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called every frame */
	virtual void Tick(float DeltaSeconds) override;

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	/** Movement */
	void MoveForward(float Value);
	void MoveRight(float Value);

	/** Camera */
	void Turn(float Value);
	void LookUp(float Value);

	/** Jump */
	void Jump();

	/**** INTERACTION *****/
public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void Interact();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		FString GetFocusedInteractableName() const;

protected:
	UPROPERTY(EditAnywhere, Category = "Interaction")
		float fMaxInteractDistance;

private:
	UPInteractableComponent* GetInteractableInView();
	UPInteractableComponent* FocusedInteractable;
	
	
};
