// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
#include "ATEBoard.generated.h"


 

UENUM(BlueprintType)
enum class EGoal : uint8 {
	LEFT = 0  UMETA(DisplayName = "Player"),
	RIGHT = 1 UMETA(DisplayName = "AI")
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
		class UBoxComponent* LeftGoal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		class UBoxComponent* RightGoal;

	UPROPERTY(VisibleAnywhere, Category = "Board Camera")
		class UCameraComponent* FollowCamera;

	//For the goals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		AActor* MiddleOfField;



	//For the points?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		TEnumAsByte<EGoal> goal;


	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		AActor* SpawnBallInMiddle;*/

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	//Function that I could call
	//getScaledBoxExtent()




	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		//Check for more info LAB UEModes-Complete 
		//That could be use to for the *Player goals* and the *AI goals* 
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
