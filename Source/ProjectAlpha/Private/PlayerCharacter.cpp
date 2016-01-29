// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectAlpha.h"
#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	// Interaction
	fMaxInteractDistance = 400;
	FocusedInteractable = NULL;


	// Initialise components
	
	// TEXT FOR DEBUG -- TO BE REMOVED
	text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TEXT"));
	text->SetWorldSize(150.f);
	text->SetHorizontalAlignment(EHTA_Center);
	text->AttachTo(RootComponent);
//	text->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	text->SetVisibility(false);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->AttachTo(RootComponent);
	SpringArmComp->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bEnableCameraLag = false;
	SpringArmComp->CameraLagSpeed = 3.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->AttachTo(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

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

	//Get interactable in view
	if (Controller && Controller->IsLocalController())
	{
		AInteractableActor* InteractableInView = GetInteractableInView();

		if (FocusedInteractable != InteractableInView)
		{
			if (FocusedInteractable)
				FocusedInteractable->EndFocus();
			
			FocusedInteractable = InteractableInView;

			if (FocusedInteractable)
				FocusedInteractable->BeginFocus();
		}
	}
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
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Interaction
	InputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
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
	AddControllerPitchInput(Value);
}

void APlayerCharacter::Jump()
{
	ACharacter::Jump();
}

void APlayerCharacter::Interact()
{
	if(FocusedInteractable)
		FocusedInteractable->Interact(this);
}

AInteractableActor* APlayerCharacter::GetInteractableInView()
{
	if(!Controller)
		return NULL;

	FVector CamLoc;
	FRotator CamRot;

	Controller->GetPlayerViewPoint(CamLoc, CamRot);

	const FVector TraceStart = CamLoc + FVector(0.0f, 0.0f, -50.0f);
	const FVector TraceDirection = (CamRot + FRotator(15.0f, 0.0f, 0.0f)).Vector();
	const FVector TraceEnd = TraceStart + TraceDirection * fMaxInteractDistance;

	FCollisionQueryParams TraceParams(FName("TraceInteractableActor"), true, this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingle(Hit, TraceStart, TraceEnd, ECC_Visibility, TraceParams);
	//GetWorld()->

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 0.2);
	//DrawDebugCone(GetWorld(), TraceStart, TraceDirection, fMaxInteractDistance, 0.349066, 0.349066, 4, FColor::Yellow, false, 0.2);

	return Cast<AInteractableActor> (Hit.GetActor());
}