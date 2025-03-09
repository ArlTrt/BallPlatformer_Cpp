// Fill out your copyright notice in the Description page of Project Settings.

#include "BallPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABallPlayer::ABallPlayer()
{
	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create Ball Mesh component
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetupAttachment(RootComponent);

	// Set collision and physics properties
	BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BallMesh->SetCollisionResponseToAllChannels(ECR_Block);
	BallMesh->SetSimulatePhysics(true);

	// Create PlayerCamera component
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(BallMesh);
	
	// Offset and rotate PlayerCamera
	PlayerCamera->SetRelativeLocation(FVector(-800.0f, 0.0f, 600.0f));
	PlayerCamera->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

 	// Set this pawn to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Ball Mesh component
		//BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
		//RootComponent = BallMesh;
}

// Called when the game starts or when spawned
void ABallPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BallMesh && PlayerCamera)
	{
		FVector BallLocation = BallMesh->GetComponentLocation();
		FVector CameraOffset = FVector(-800.0f, 0.0f, 600.0f);
		PlayerCamera->SetWorldLocation(BallLocation + CameraOffset);
	}
}

// Called to bind functionality to input
void ABallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Add input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		//Get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			//Add input context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABallPlayer::MoveInput);
		Input->BindAction(JumpAction, ETriggerEvent::Started, this, &ABallPlayer::Jump);
	}
}

void ABallPlayer::MoveInput(const FInputActionValue& Value)
{
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Pressed Move Action");

	FVector2D InputVector = Value.Get<FVector2D>();

	FVector Impulse = FVector(InputVector.Y * 10.0f, InputVector.X * 10.0f, 0.0f);

	// Apply impulse to pawn
	if (BallMesh)
	{
		BallMesh->AddImpulse(Impulse, NAME_None, true);
	}
}

void ABallPlayer::Jump()
{
	if (JumpCount < 2 && BallMesh)
	{
		BallMesh->AddImpulse(FVector(0, 0, JumpImpulse), NAME_None, true);

		JumpCount++;
	}
}

void ABallPlayer::ResetJump()
{
	JumpCount = 0;
	bIsGrounded = true;
}

void ABallPlayer::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "notifyhit");
	if (HitNormal.Z > 0.7f)
	{
		ResetJump();
	}
}

