// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEGameModeBase.h"
#include "EngineUtils.h" //Needed for TActorIterator
#include "Kismet/GameplayStatics.h"
#include"ATEBoard.h"

void AATEGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    for (TActorIterator<AATEBoard> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        controller->SetViewTarget(*ActorItr);
    }
}
