// Fill out your copyright notice in the Description page of Project Settings.

#include "ATEBoard.h"
#include "Components/BoxComponent.h"
//Fuction that I can use ,editable mesh(),...
//For the static mesh(Board)
#include "Components/StaticMeshComponent.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "ATEBall.h"
#include "ATEGameModeBase.h"
#include "ATEGameStateBase.h"
#include "ATEAIPawn.h"

// Sets default values
AATEBoard::AATEBoard()
{
	//Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	////LeftBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	//LeftBoundary = CreateDefaultSubobject<UBoxComponent>("Left Collision");
	////LeftBoundary->SetCollisionProfileName("BlockAllDynamic");
	//LeftBoundary->SetCollisionProfileName("OverlapAllDynamic");
	//LeftBoundary->SetSimulatePhysics(false);
	////LeftBoundary->OnComponentHit.AddDynamic(this, &AATEBoard::OnHit);
	//LeftBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//LeftBoundary->SetupAttachment(RootComponent);

	////RightBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	//LeftBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	//RightBoundary = CreateDefaultSubobject<UBoxComponent>("Right Collision");
	////RightBoundary->SetCollisionProfileName("BlockAllDynamic");
	//RightBoundary->SetCollisionProfileName("OverlapAllDynamic");
	//RightBoundary->SetSimulatePhysics(false);
	////RightBoundary->OnComponentHit.AddDynamic(this, &AATEBoard::OnHit);
	//RightBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	//RightBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//RightBoundary->SetupAttachment(RootComponent);



	FollowCamera = CreateDefaultSubobject<UCameraComponent>("Board Camera");
	FollowCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	FollowCamera->SetOrthoWidth(1750.0f);
	FollowCamera->SetupAttachment(RootComponent);

}

//void AATEBoard::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	OtherActor->Destroy();
//	SpawnActor();
//
//	/*if (OtherActor->IsA<AATEBall>())
//	{
//
//		AATEGameModeBase* gameMode = Cast<AATEGameModeBase>(GetWorld()->GetAuthGameMode());
//
//		AATEGameStateBase* gameState = gameMode->GetGameState<AATEGameStateBase>();
//
//		if (goal == EGoal::LEFT)
//			gameState->NumberOfLeftGoals++;
//		else
//			gameState->NumberOfRightGoals++;
//			
//	}*/
//
//}

// Called when the game starts or when spawned
//void AATEBoard::BeginPlay()
//{
//	SpawnActor();
//	Super::BeginPlay();
//
//}

// Called every frame
void AATEBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AATEBoard::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	if (OtherActor && OtherActor != this)
//	{
//		if (GEngine)
//		{
//			OtherActor->Destroy();
//			SpawnActor();
//			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has Hit"), *OtherActor->GetName()));
//		}
//	}
//}

//void AATEBoard::SpawnActor()
//{
//	//IF the BallTemplate NOT EQUAL to nullptr
//	if (BallTemplate != nullptr)
//	{
//		//DECLARE a variable called World of type const UWorld* and assign it to the return value of GetWorld()
//		UWorld* World = GetWorld();
//		//IF World is NOT EQUAL to nullptr
//		if (World)
//		{
//
//			FActorSpawnParameters SpawnParams;
//
//			SpawnParams.Owner = this;
//
//			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
//
//
//			FTransform SpawnTransform;// = SpawnPointComponent->GetComponentTransform();
//
//			AATEBall* SpawnedActor = World->SpawnActor<AATEBall>(BallTemplate, SpawnTransform, SpawnParams);
//	
//			AI_Paddle->SetBall(SpawnedActor);
//		}
//
//	}
//}



void AATEBoard::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

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


