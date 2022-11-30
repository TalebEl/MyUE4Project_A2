// Fill out your copyright notice in the Description page of Project Settings.


#include "ATETriggerBoxActor.h"
#include "Components/BoxComponent.h"
#include "ATEGameModeBase.h"
#include "ATEGameStateBase.h"
#include "ATEBall.h"

// Sets default values
AATETriggerBoxActor::AATETriggerBoxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GoalTrigger = CreateDefaultSubobject<UBoxComponent>("SceneRoot");

	GoalTrigger->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	//3
	GoalTrigger->SetSimulatePhysics(false);
	//4 - Add a Step and show camera .
	GoalTrigger->SetCollisionProfileName("OverlapAllDynamic");
	//5	
	GoalTrigger->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//6
	GoalTrigger->OnComponentBeginOverlap.AddDynamic(this, &AATETriggerBoxActor::BeginOverlap);
	GoalTrigger->OnComponentEndOverlap.AddDynamic(this, &AATETriggerBoxActor::EndOverlap);

	SetRootComponent(GoalTrigger);

}

void AATETriggerBoxActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OtherActor->GetName()));
		}

		//WEEK 7
		//ABall* ball = Cast<ABall>(OtherActor);
		if (OtherActor->IsA<AATEBall>())
		{
			//CALL TeleportTo() on OtherActor passing in MiddleOfField->GetActorLocation(), FRotator::ZeroRotator
			//OtherActor->TeleportTo(MiddleOfField->GetActorLocation(), FRotator::ZeroRotator);

			AATEGameModeBase* gameMode = Cast<AATEGameModeBase>(GetWorld()->GetAuthGameMode());

			AATEGameStateBase* gameState = gameMode->GetGameState<AATEGameStateBase>();
			//IF goal IS EGoal::LEFT

			if (goal == EGoal::LEFT)
				//INCREMENT 	NumberOfLeftGoals property on gameState
				gameState->NumberOfLeftGoals++;
			//ELSE
			else
				//INCREMENT NumberOfRightGoals property on gameState
				gameState->NumberOfRightGoals++;

		}
	}
}

void AATETriggerBoxActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

// Called when the game starts or when spawned
void AATETriggerBoxActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATETriggerBoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

