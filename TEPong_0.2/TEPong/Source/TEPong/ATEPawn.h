// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Pawn.h"
#include "ATEPawn.generated.h"


//My Paddle class
UCLASS()
class TEPONG_API AATEPawn : public APawn
{
	GENERATED_BODY()

protected:
	// Sets default values for this pawn's properties
	AATEPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ball Bounce")
		class UProjectileMovementComponent* BallBounce;*/

	////This will handle meshe(s)
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh Component")
	//	UStaticMeshComponent* PaddleComponent;

	//FloatingPawnMovement is a movement component that provides simple movement for any Pawn class.
	//Functions that I might use: bool LimitWorldBounds(),...
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh Component")
		UFloatingPawnMovement* MeshComponent;*/

	UPROPERTY(EditAnywhere, Category = "Paddle Visual")
		class UPaperSpriteComponent* PawnSpriteComponent;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
		class UBoxComponent* PlayerRootCollisionBox;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement Speed")
		float NormalSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement Speed")
		float FastSpeed;


public:
	float Speed;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	//Function to move to paddle UP and DOWN
	void moveUpandDown(float value);

	void SpeedUp();

	void SlowDown();



	float moveUpAndDown;
	


	void SetDirection(const FVector Direction);

	



};
