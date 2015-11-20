// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialise components
	
	// TEXT FOR DEBUG -- TO BE REMOVED
	text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TEXT"));
	text->SetWorldSize(150.f);
	text->SetHorizontalAlignment(EHTA_Center);
	text->AttachTo(RootComponent);
	RootComponent = text;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->AttachTo(RootComponent);
	SpringArmComp->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 2.0f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachTo(SpringArmComp);

	// Auto possess player
	AutoPossessPlayer = EAutoReceiveInput::Player0;



	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// Movement
	InputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// Camera
	InputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	InputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

	// Jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}

}

void APlayerCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0)
	{
		const FRotator Rotation = GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	FRotator Rotation = CameraComp->GetComponentRotation();
	Rotation.Pitch += Value;
	CameraComp->SetWorldRotation(Rotation);
}

void APlayerCharacter::Jump()
{
	return;
}