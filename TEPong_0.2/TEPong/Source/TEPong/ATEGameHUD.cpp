// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEGameHUD.h"

#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AATEGameHUD::AATEGameHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> playerHud(TEXT("/Game/Blueprints/UI/PlayerUI"));
    if (playerHud.Succeeded())
        PlayerGuiClass = playerHud.Class;
}

void AATEGameHUD::BeginPlay()
{
    
    PlayerGui = CreateWidget<UUserWidget>(GetGameInstance(), PlayerGuiClass);
    
    //Add it to the game's viewport
    PlayerGui->AddToViewport();

}
