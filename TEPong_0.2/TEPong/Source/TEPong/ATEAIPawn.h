// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ATEPawn.h"
#include "ATEBall.h"
#include "GameFramework/Pawn.h"
#include "CoreMinimal.h"
#include "ATEAIPawn.generated.h"



UCLASS()
class TEPONG_API AATEAIPawn : public AATEPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AATEAIPawn();

	UFUNCTION(BlueprintCallable,Category = "AAA")
		void SetBall(class AATEBall* BallToSet) { Ball = BallToSet; }

	UPROPERTY(VisibleAnywhere, Category = "Difficulty Factor")
		float DuficultyFactor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "config")
		class AATEBall* Ball;

	UPROPERTY()
		FVector Initialocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	

public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
