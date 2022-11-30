// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATETriggerBoxActor.generated.h"


UENUM(BlueprintType)
enum class EGoal : uint8 {
	LEFT = 0  UMETA(DisplayName = "LEFT"),
	RIGHT = 1 UMETA(DisplayName = "RIGHT")
};

UCLASS()
class TEPONG_API AATETriggerBoxActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATETriggerBoxActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Box Collision")
		class UBoxComponent* GoalTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Goal)
		TEnumAsByte<EGoal> goal;


	UFUNCTION()
		//Check for more info LAB UEModes-Complete 
		//That could be use to for the *Player goals* and the *AI goals* 
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
