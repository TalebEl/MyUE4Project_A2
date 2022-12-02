// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ATEPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class TEPONG_API AATEPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

    virtual void OnPossess(APawn* aPawn) override;
    virtual void OnUnPossess() override;

protected:
    virtual void SetupInputComponent() override;

    virtual void AcknowledgePossession(APawn* PossesedPawn) override;

    void moveUpandDown(float value);
   

    class AATEPawn* MyPawn;
	
};









