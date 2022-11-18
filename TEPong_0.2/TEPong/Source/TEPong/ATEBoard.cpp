// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEBoard.h"

// Sets default values
AATEBoard::AATEBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("SceneRoot");
	//2
	TriggerBox->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	//3
	TriggerBox->SetSimulatePhysics(false);
	//4 - Add a Step and show camera .
	TriggerBox->SetCollisionProfileName("OverlapAllDynamic");
	//5	
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	//6
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATriggerCollision::BeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATriggerCollision::EndOverlap);

	SetRootComponent(TriggerBox);

}

// Called when the game starts or when spawned
void AATEBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AATEBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AATEBoard::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AATEBoard::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

