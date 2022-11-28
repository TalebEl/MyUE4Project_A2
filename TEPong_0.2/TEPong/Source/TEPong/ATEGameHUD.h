// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ATEGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class TEPONG_API AATEGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
    AATEGameHUD();

    UPROPERTY(EditAnywhere, Category = "Game Hud")
        TSubclassOf<class UUserWidget> PlayerGuiClass;
       
    UPROPERTY()
        class UUserWidget* PlayerGui;

protected:
    virtual void BeginPlay() override;
};
