// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
//Fuction that I can use ,editable mesh(),...
//For the static mesh(Board)
#include "Components/StaticMeshComponent.h"
#include "ATEBoard.h"

// Sets default values
AATEBoard::AATEBoard()
{
 	 //Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creates an instance of UBoxComponent 
	BoxCollsion = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxCollsion->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	BoxCollsion->SetSimulatePhysics(false);
	BoxCollsion->SetCollisionProfileName("OverlapAllDynamic");
	BoxCollsion->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxCollsion->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	BoxCollsion->OnComponentEndOverlap.AddDynamic(this, &AATEBoard::EndOverlap);
	SetRootComponent(BoxCollsion);


	//Static mesh Component
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Components");


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

