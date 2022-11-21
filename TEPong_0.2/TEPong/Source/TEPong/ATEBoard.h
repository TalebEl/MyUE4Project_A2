// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/BoxComponent.h"
#include "ATEBoard.generated.h"


 



//Not sure I could use that for the player points
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

	//The trigger Box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		 class UBoxComponent* BoxCollsion;

	//For the points?
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		TEnumAsByte<EGoal> goal;*/


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
