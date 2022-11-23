// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BoxComponent.h"
//Fuction that I can use ,editable mesh(),...
//For the static mesh(Board)
#include "Components/StaticMeshComponent.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "ATEBoard.h"
#include "ATEBall.h"
#include "ATEGameModeBase.h"
#include "ATEGameStateBase.h"

// Sets default values
AATEBoard::AATEBoard()
{
 	 //Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creates an instance of UBoxComponent 
	//BoxCollsion = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	//BoxCollsion->SetBoxExtent(FVector(120, 50, 140)); //100,10,100
	//BoxCollsion->SetSimulatePhysics(false);
	//BoxCollsion->SetCollisionProfileName("OverlapAllDynamic");
	//BoxCollsion->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//BoxCollsion->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	//BoxCollsion->OnComponentEndOverlap.AddDynamic(this, &AATEBoard::EndOverlap);
	//SetRootComponent(BoxCollsion);

	BoardVisual = CreateDefaultSubobject<UPaperSpriteComponent>("Box Visual");
	//Setting the rootComponent to the boardVisual
	SetRootComponent(BoardVisual);
	
	


	TopBoundary = CreateDefaultSubobject<UBoxComponent>("TopBox Collision");
	TopBoundary->SetCollisionProfileName("BlockAllDynamic");
	TopBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	TopBoundary->SetupAttachment(RootComponent);



	BottomBoundary = CreateDefaultSubobject<UBoxComponent>("BottomBox Collision");
	BottomBoundary->SetCollisionProfileName("BlockAllDynamic");
	BottomBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BottomBoundary->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("Board Camera");
	FollowCamera->SetupAttachment(RootComponent);

	//Left Goal
	//LeftGoal = CreateDefaultSubobject<UBoxComponent>("LeftBox Overlap");
	////LeftGoal->SetSimulatePhysics(false);
	//LeftGoal->SetCollisionProfileName("OverlapAllDynamic");
	//LeftGoal->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//LeftGoal->SetupAttachment(RootComponent);
	//LeftGoal->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	////Right Goal
	//RightGoal = CreateDefaultSubobject<UBoxComponent>("RightBox Overlap");
	////RightGoal->SetSimulatePhysics(false);
	//RightGoal->SetCollisionProfileName("OverlapAllDynamic");
	//RightGoal->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//RightGoal->SetupAttachment(RootComponent);
	//RightGoal->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	
	


	//RightGoal->SetupAttachment(RootComponent);

	//Static mesh Component
	//MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Components");


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

//void AATEBoard::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor && OtherActor != this)
//	{
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OtherActor->GetName()));
//		}
//
//		//WEEK 7
//		//ABall* ball = Cast<ABall>(OtherActor);
//		if (OtherActor->IsA<AATEBall>())
//		{
//			//CALL TeleportTo() on OtherActor passing in MiddleOfField->GetActorLocation(), FRotator::ZeroRotator
//			OtherActor->TeleportTo(MiddleOfField->GetActorLocation(), FRotator::ZeroRotator);
//
//			//DECLARE a temporary variable called gameMode of type AUEGameMode* and assign it to the return value of Cast<AUEGameMode>( GetWorld()->GetAuthGameMode() )
//			AATEGameModeBase* gameMode = Cast<AATEGameModeBase>(GetWorld()->GetAuthGameMode());
//			//DECLARE a temporary variable called gameState of type AUEGameState* and assign it to the return value of  gameMode->GetGameState<AUEGameState>()
//			AATEGameStateBase* gameState = gameMode->GetGameState<AATEGameStateBase>(); //Cast<AUEGameState> (gameMode->GetGameState<>())
//			
//			//IF goal IS EGoal::LEFT
//			if (goal == EGoal::LEFT)
//				//INCREMENT 	NumberOfLeftGoals property on gameState
//				gameState->NumberOfLeftGoals++;
//			//ELSE
//			else
//				//INCREMENT NumberOfRightGoals property on gameState
//				gameState->NumberOfRightGoals++;
//
//		}
//	}
//}

//void AATEBoard::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if (OtherActor && OtherActor != this)
//	{
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Volume"), *OtherActor->GetName()));
//		}
//	}
//}

