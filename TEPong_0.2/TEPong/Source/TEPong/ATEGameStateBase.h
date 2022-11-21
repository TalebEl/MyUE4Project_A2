// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ATEGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TEPONG_API AATEGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	AATEGameStateBase();

	UFUNCTION(BlueprintCallable, Category = "Pickups")
		int GetNumberOfLeftGoals();

	UFUNCTION(BlueprintCallable, Category = "Pickups")
		int GetNumberOfRightGoals();

	float NumberOfLeftGoals;
	float NumberOfRightGoals;

	
};
