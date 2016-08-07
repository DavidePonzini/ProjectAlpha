// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "Interactable.h"
#include "PlayerCharacter.generated.h"


class AInteractableActor;


UCLASS()
class PROJECTALPHA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	/***** COMPONENTS *****/
public:
	// Camera components
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		USpringArmComponent* SpringArmComp;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCharacter | Camera")
		UCameraComponent* CameraComp;

public:
	/** Sets default values for this character's properties */
	APlayerCharacter();

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
	IInteractable* GetInteractableInView();
	IInteractable* FocusedInteractable;
	
	
};
