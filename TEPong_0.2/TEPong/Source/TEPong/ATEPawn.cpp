// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
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

	//UBoxComponent
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
	SetDirection(FVector::UpVector); // temp might change that
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
		PawnSpriteComponent->SetRelativeRotation(FRotator(0, 180, 0));
	}
}


// Called every frame
void AATEPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();


	//NOT WORKING 

	//if (moveUpandDown != 0)
	//{
	//	//ASSIGN NewLocation to the the sum of the Actors Current Location and the product of the Actors Forward Vector and the MovementForward value i.e GetActorLocation() + (GetActorForwardVector() * MovementForward)
	//	NewLocation = GetActorLocation() + (GetActorUpVector() * -moveUpandDown * Speed);
	//}
	

	//CALL SetActorLocation() passing in NewLocation
	SetActorLocation(NewLocation);

}

 

