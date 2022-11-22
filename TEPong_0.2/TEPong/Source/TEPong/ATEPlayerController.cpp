// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPlayerController.h"
#include "ATEPawn.h"

//AATEPawn

void AATEPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

    MyPawn = Cast<AATEPawn>(aPawn);
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow,
        "AMyPlayerController::Possess: - " + aPawn->GetName());
}

void AATEPlayerController::OnUnPossess()
{
    APawn* posessedPawn = Cast<APawn>(GetOwner());
    if (posessedPawn)
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow,
            "AMyPlayerController::UnPossess: - " + GetOwner()->GetName());

    Super::OnUnPossess();
}

void AATEPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent != nullptr)
    {
        InputComponent->BindAxis("MoveForward", this, &AATEPlayerController::moveUpandDown);
        InputComponent->BindAction("Speed", IE_Pressed, this, &AATEPlayerController::SpeedUp);
        InputComponent->BindAction("Speed", IE_Released, this, &AATEPlayerController::SlowDown);
    }
}

void AATEPlayerController::AcknowledgePossession(APawn* PossesedPawn)
{

}

void AATEPlayerController::moveUpandDown(float value)
{
    if (MyPawn)
        MyPawn->moveUpandDown(value);
}

void AATEPlayerController::SpeedUp()
{
    if (MyPawn)
        MyPawn->SpeedUp();
}

void AATEPlayerController::SlowDown()
{
    if (MyPawn)
        MyPawn->SlowDown();
}
