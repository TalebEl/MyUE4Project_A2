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

	//Called to set new ball reference
	UFUNCTION(BlueprintCallable,Category = "AAA")
		void SetBall(class AATEBall* BallToSet) { Ball = BallToSet; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Difficulty Factor")
		float DuficultyFactor;

	//On board ball reference
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "config")
		class AATEBall* Ball;

	//AI Initial Location
	UPROPERTY()
		FVector Initialocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;


private:

	

public:	
	

};
