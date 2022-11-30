// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEAIPawn.h"

// Sets default values
AATEAIPawn::AATEAIPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DuficultyFactor = 100.0f;

}

// Called when the game starts or when spawned
void AATEAIPawn::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AATEAIPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Ball)
	{
		FVector BallLocation = Ball->GetActorLocation();

		FVector TargetLocation = GetActorLocation();

		TargetLocation.Z = BallLocation.Z;

		SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), TargetLocation, DeltaSeconds, DuficultyFactor));

	}
	//Iniatial Location
	else
	{
		SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), Initialocation, DeltaSeconds, DuficultyFactor));
	}

}


