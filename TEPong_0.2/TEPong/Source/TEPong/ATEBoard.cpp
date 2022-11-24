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




	 LeftBoundary = CreateDefaultSubobject<UBoxComponent>("Left Collision");
	 LeftBoundary->SetCollisionProfileName("BlockAllDynamic");
	 LeftBoundary->SetSimulatePhysics(false);
	 //LeftBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	 LeftBoundary->OnComponentHit.AddDynamic(this, &AATEBoard::OnHit);
	 LeftBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	 LeftBoundary->SetupAttachment(RootComponent);

	 RightBoundary = CreateDefaultSubobject<UBoxComponent>("Right Collision");
	 //RightBoundary->OnComponentBeginOverlap.AddDynamic(this, &AATEBoard::BeginOverlap);
	 RightBoundary->SetCollisionProfileName("BlockAllDynamic");
	 RightBoundary->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	 RightBoundary->SetupAttachment(RootComponent);

	

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

void AATEBoard::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
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

void AATEBoard::SpawnActor()
{
	//IF the BallTemplate NOT EQUAL to nullptr
	if (BallTemplate != nullptr)
	{
		//DECLARE a variable called World of type const UWorld* and assign it to the return value of GetWorld()
		UWorld* World = GetWorld();
		//IF World is NOT EQUAL to nullptr
		if (World)
		{
			//DECLARE a variable called SpawnParams of type FActorSpawnParameters
			FActorSpawnParameters SpawnParams;
			//SET SpawnParams Owner to this
			SpawnParams.Owner = this;
			//SET SpawnParams SpawnCollisionHandlingOverride property to ESpawnActorCollisionHandlingMethod::AlwaysSpawn
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			//DECLARE a variable called SpawnTransform of type FTransform and assign it to the return value of SpawnPointComponent->GetComponentTransform()
			FTransform SpawnTransform;// = SpawnPointComponent->GetComponentTransform();
			//DECLARE a variable called SpawnedActor of type AFallingActor* and assign it to the return value of World->SpawnActor<type>(args..), 
			//passing in AFallingActor as the type argument (inside <>) and in function arguments pass --> BallTemplate, SpawnTransform, SpawnParams
			AATEBall* SpawnedActor = World->SpawnActor<AATEBall>(BallTemplate, SpawnTransform, SpawnParams);
			//IF SpawnedActor NOT EQUAL to nullptr
			if (SpawnedActor)
			{
				//DECLARE a variable called direction of type FVector and assign it to the return value of --> FRotationMatrix(SpawnTransform.Rotator()).GetScaledAxis(EAxis::X)
				// direction = FRotationMatrix(SpawnTransform.Rotator()).GetScaledAxis(EAxis::X);
				//DECLARE a variable called physicsComponent of type UPrimitiveComponent* and assign it to the return value of --> SpawnedActor->GetPhysicsComponent()
				//UPrimitiveComponent* physicsComponent = SpawnedActor->GetPhysicsComponent();
				//CALL AddForce(..) on the physicsComponent and pass in --> direction * 1000000, NAME_None, true
				//physicsComponent->AddForce(direction * 1000000, NAME_None, true);
			}
			//ENDIF SpawnedActor NOT EQUAL to nullptr
		}
		//ENDIF World is NOT EQUAL to nullptr

	}//ENDIF the BallTemplate NOT EQUAL to nullptr

}

void AATEBoard::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->Destroy();
	int x = 2;
}

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

