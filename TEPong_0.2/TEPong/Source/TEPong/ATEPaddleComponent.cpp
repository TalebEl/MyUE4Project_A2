// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPaddleComponent.h"
//#include "GameFramework/PawnMovementComponent.h"

// Sets default values for this component's properties



// Called every frame
void UATEPaddleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


    
    //FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    //if (!DesiredMovementThisFrame.IsNearlyZero())
    //{
    //    FHitResult Hit;
    //    SafeMoveUpdatedComponent(DesiredMovementThisFrame * Speed, UpdatedComponent->GetComponentRotation(), true, Hit); //Update the pawns Movement 
}

