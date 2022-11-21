// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
//#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMesh.h"

// Sets default values
AATEPawn::AATEPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//creates a new instance in heap
	BallBounce = CreateDefaultSubobject<UProjectileMovementComponent>("Ball Bounce");
	BallBounce->Bounciness = 1.0f;

	PaddleComponent = CreateDefaultSubobject<UStaticMeshComponent>("Paddle Component");
	//root?
	//RootComponent:The component that defines the transform(location, rotation, scale) of this Actor in the world, all other components must be attached to this one somehow
	RootComponent = PaddleComponent;
}

// Called when the game starts or when spawned
void AATEPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AATEPawn::moveUpandDown(float value)
{

}


// Called every frame
void AATEPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 //Called to bind functionality to input
void AATEPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);




}

