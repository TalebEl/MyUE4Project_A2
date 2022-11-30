// Fill out your copyright notice in the Description page of Project Settings.


#include "ATETriggerBoxActor.h"
#include "Components/BoxComponent.h"
#include "ATEGameModeBase.h"
#include "ATEGameStateBase.h"
#include "ATEBall.h"
#include "ATEAIPawn.h"

// Sets default values
AATETriggerBoxActor::AATETriggerBoxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GoalTrigger = CreateDefaultSubobject<UBoxComponent>("Left Collision");
	//GoalTrigger->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	GoalTrigger->SetSimulatePhysics(false);
	GoalTrigger->SetCollisionProfileName("OverlapAllDynamic");
	GoalTrigger->SetCollisionProfileName("BlockAllDynamic");
	GoalTrigger->OnComponentHit.AddDynamic(this, &AATETriggerBoxActor::OnHit);
	GoalTrigger->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
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

void AATETriggerBoxActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			OtherActor->Destroy();
			SpawnActor();
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has Hit"), *OtherActor->GetName()));
		}
	}
}

void AATETriggerBoxActor::SpawnActor()
{
	//IF the BallTemplate NOT EQUAL to nullptr
	if (BallTemplate != nullptr)
	{
		//DECLARE a variable called World of type const UWorld* and assign it to the return value of GetWorld()
		UWorld* World = GetWorld();
		//IF World is NOT EQUAL to nullptr
		if (World)
		{

			FActorSpawnParameters SpawnParams;

			SpawnParams.Owner = this;

			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;


			FTransform SpawnTransform;// = SpawnPointComponent->GetComponentTransform();

			AATEBall* SpawnedActor = World->SpawnActor<AATEBall>(BallTemplate, SpawnTransform, SpawnParams);

			AI_Paddle->SetBall(SpawnedActor);
		}

	}
}

