// Fill out your copyright notice in the Description page of Project Settings.


#include "ATETriggerCollision.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PaperSpriteComponent.h"
//#include "Camera/CameraComponent.h"
#include "ATEBall.h"
#include "ATEGameModeBase.h"
#include "ATEGameStateBase.h"
#include "ATEAIPawn.h"

// Sets default values
AATETriggerCollision::AATETriggerCollision()
{
	PrimaryActorTick.bCanEverTick = true;
	//TriggerBox = CreateDefaultSubobject<UBoxComponent>("SceneRoot");

	//TriggerBox->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	//
	//TriggerBox->SetSimulatePhysics(false);
	//
	//TriggerBox->SetCollisionProfileName("OverlapAllDynamic");
	//
	//TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	//TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AATETriggerCollision::BeginOverlap);
	//TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AATETriggerCollision::EndOverlap);
	
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("Right Collision");
	//RightBoundary->SetCollisionProfileName("BlockAllDynamic");
	TriggerBox->SetCollisionProfileName("OverlapAllDynamic");
	TriggerBox->SetSimulatePhysics(false);
	//RightBoundary->OnComponentHit.AddDynamic(this, &AATEBoard::OnHit);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AATETriggerCollision::BeginOverlap);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	TriggerBox->SetupAttachment(RootComponent);

	SetRootComponent(TriggerBox);

	
}

void AATETriggerCollision::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OtherActor->GetName()));
		}
		if(OtherActor->IsA<AATEBall>())
		{
			//CALL TeleportTo() on OtherActor passing in MiddleOfField->GetActorLocation(), FRotator::ZeroRotator
			//OtherActor->TeleportTo(MiddleOfField->GetActorLocation(), FRotator::ZeroRotator);
			AATEGameModeBase* gameMode = Cast<AATEGameModeBase>(GetWorld()->GetAuthGameMode());

			AATEGameStateBase* gameState = gameMode->GetGameState<AATEGameStateBase>();

		
			if(goal == EGoal::LEFT)
			   gameState->NumberOfLeftGoals++;
			else
				gameState->NumberOfRightGoals++;

		}
	}
}

void AATETriggerCollision::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Volume"), *OtherActor->GetName()));
		}
	}
}

// Called when the game starts or when spawned
void AATETriggerCollision::BeginPlay()
{
	Super::BeginPlay();

	//rawDebugBox(GetWorld(), GetActorLocation(), TriggerBox->GetUnscaledBoxExtent(), FColor::Green, true, 999, 0, 5);
}

// Called every frame
void AATETriggerCollision::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

