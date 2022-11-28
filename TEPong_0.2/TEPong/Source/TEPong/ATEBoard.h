// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
#include "ATEBoard.generated.h"


 

UENUM(BlueprintType)
enum class EGoal : uint8 {
	LEFT = 0  UMETA(DisplayName = "LEFT"),
	RIGHT = 1 UMETA(DisplayName = "RIGHT")
};

UCLASS()
class TEPONG_API AATEBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATEBoard();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Board Visual")
		class UPaperSpriteComponent* BoardVisual;

	//The trigger Box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		 class UBoxComponent* TopBoundary;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		class UBoxComponent* BottomBoundary;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		class UBoxComponent* LeftBoundary;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		class UBoxComponent* RightBoundary;

	

	UPROPERTY(VisibleAnywhere, Category = "Board Camera")
		class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AATEBall> BallTemplate;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	//For the points
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		TEnumAsByte<EGoal> goal;

	//For the goals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		AActor* MiddleOfField;

	void SpawnActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		//Check for more info LAB UEModes-Complete 
		//That could be use to for the *Player goals* and the *AI goals* 
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
