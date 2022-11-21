// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
//#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMesh.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AATEPawn::AATEPawn()
{
 	
	/*PrimaryActorTick.bCanEverTick = true;
	BallBounce = CreateDefaultSubobject<UProjectileMovementComponent>("Ball Bounce");
	BallBounce->Bounciness = 1.0f;

	PaddleComponent = CreateDefaultSubobject<UStaticMeshComponent>("Paddle Component");*/

	PawnSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Sprite");
	PawnSpriteComponent->SetupAttachment(RootComponent);
	PawnSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PlayerRootCollisionBox = CreateDefaultSubobject<UBoxComponent>("SceneRoot");

	
	PlayerRootCollisionBox->SetSimulatePhysics(true);

	PlayerRootCollisionBox->SetCollisionProfileName("BlockAllDynamic");
	PlayerRootCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	PlayerRootCollisionBox->GetBodyInstance()->bLockRotation = true;// BodyInstance.bLockXRotation = true; SetConstraintMode(EDOFMode::XZPlane)
	PlayerRootCollisionBox->GetBodyInstance()->bLockXRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockYRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockZRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockYTranslation = true;
	SetRootComponent(PlayerRootCollisionBox);


}

// Called when the game starts or when spawned
void AATEPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AATEPawn::moveUpandDown(float value)
{
	moveUpAndDown = value;

	if (value > 0)
		SetDirection(FVector::UpVector);

	if (value < 0)
		SetDirection(FVector::DownVector);
}

void AATEPawn::SpeedUp()
{
	Speed = FastSpeed;
}

void AATEPawn::SlowDown()
{
	Speed = NormalSpeed;
}

//Called to bind functionality to input
void AATEPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void AATEPawn::SetDirection(const FVector Direction)
{
	/*CORE_API const FVector FVector::UpVector(0.0f, 0.0f, 1.0f);
	CORE_API const FVector FVector::DownVector(0.0f, 0.0f, -1.0f);*/

	if (Direction == FVector::UpVector) {
		PawnSpriteComponent->SetRelativeRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::DownVector) {
		PawnSpriteComponent->SetRelativeRotation(FRotator(0, 0, 0));
	}
}


// Called every frame
void AATEPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 

