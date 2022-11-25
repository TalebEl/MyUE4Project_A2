// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEPawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/BoxComponent.h"

// Sets default values
AATEPawn::AATEPawn()
{
	//UBoxComponent
	PlayerRootCollisionBox = CreateDefaultSubobject<UBoxComponent>("SceneRoot");
	//PlayerRootCollisionBox->SetSimulatePhysics(true);

	PlayerRootCollisionBox->SetCollisionProfileName("BlockAll");
	PlayerRootCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//PlayerRootCollisionBox->SetRelativeRotation(FRotator(0, 90.0f, 0));
	//PlayerRootCollisionBox->GetBodyInstance()->bLockRotation = true;// BodyInstance.bLockXRotation = true; SetConstraintMode(EDOFMode::XZPlane)
	//PlayerRootCollisionBox->GetBodyInstance()->bLockXRotation = true;
	//PlayerRootCollisionBox->GetBodyInstance()->bLockYRotation = true;
	//PlayerRootCollisionBox->GetBodyInstance()->bLockZRotation = true;
	//PlayerRootCollisionBox->GetBodyInstance()->bLockYTranslation = true;
	//PlayerRootCollisionBox->GetBodyInstance()->bLockXTranslation = true;
	SetRootComponent(PlayerRootCollisionBox);
	//PlayerRootCollisionBox->SetWorldLocation(FVector(-400, 2.0f, 0));
//	PlayerRootCollisionBox->SetRelativeLocation(FVector(-400, 2.0f, 0));
	//PlayerRootCollisionBox->SetupAttachment(RootComponent);
	isPlayer = false;
 	
	//UPaperSpriteComponent
	PawnSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Sprite");
	//Attach
	//PawnSpriteComponent->SetSprite(SpriteAssetObj.Object);//SetStaticMesh(ConstructorStatics.PlaneMesh.Get());
	static ConstructorHelpers::FObjectFinder<UObject> SpriteAssetObj(TEXT("/Game/Sprites/PlayerPaddle_Sprite.PlayerPaddle_Sprite"));
	if (SpriteAssetObj.Object)
	{
		Sprite = SpriteAssetObj.Object;
	}
	
	
	PawnSpriteComponent->SetupAttachment(RootComponent);
	PawnSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	
	

}

// Called when the game starts or when spawned
void AATEPawn::BeginPlay()
{
	Super::BeginPlay();
	if (isPlayer)
	{
		
		//PawnSpriteComponent->SetRelativeRotation(FRotator(90, 0, 90));
		if (Sprite)
		{
			PawnSpriteComponent->SetSprite(Cast<UPaperSprite>(Sprite));
		}

		PlayerRootCollisionBox->SetRelativeLocation(FVector(-400, 2.0f, 0));
		PawnSpriteComponent->SetRelativeRotation(FRotator(90, 0, 90));
		PlayerRootCollisionBox->SetBoxExtent(FVector(30, 30.0f, 138));
		//PlayerRootCollisionBox->SetRelativeRotation(FRotator(180, 90, 180));
	
	}
	
	//SetDirection(FVector::UpVector); // temp might change that
}




void AATEPawn::moveUpandDown(float value)
{
	moveUpAndDown = value;

	if (value > 0)
		SetDirection(1.0f);

	if (value < 0)
		SetDirection(-1.0f);
}

void AATEPawn::SpeedUp()
{
	Speed = FastSpeed;
}

void AATEPawn::SlowDown()
{
	Speed = NormalSpeed;
}

//Called to bind functionality to input
void AATEPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

void AATEPawn::SetDirection(float Direction)
{
	/*CORE_API const FVector FVector::UpVector(0.0f, 0.0f, 1.0f);
	CORE_API const FVector FVector::DownVector(0.0f, 0.0f, -1.0f);*/
	m_Direction = FVector(0.0f, 0.0f, 0.0f);

	if (Direction == 1.0f) {
		//PawnSpriteComponent->SetRelativeRotation(FRotator(0, 0, 0));
		
		m_Direction = FVector(0.0f,0.0f,Direction);
	}
	else if (Direction == -1.0f) {
		m_Direction = FVector(0.0f, 0.0f, Direction);
	}
	//SetActorLocation(GetActorLocation() + SetDirection * 5000.0f);
}


// Called every frame
void AATEPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector NewLocation = GetActorLocation();

	if (!m_Direction.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (m_Direction * 200.0f * DeltaTime);
		SetActorLocation(NewLocation);

		FVector OldLocation = GetActorLocation();
		int x = 2;
	}

	//NOT WORKING 

	//if (moveUpandDown != 0)
	//{
	//	//ASSIGN NewLocation to the the sum of the Actors Current Location and the product of the Actors Forward Vector and the MovementForward value i.e GetActorLocation() + (GetActorForwardVector() * MovementForward)
	//	NewLocation = GetActorLocation() + (GetActorUpVector() * -moveUpandDown * Speed);
	//}
	

	//CALL SetActorLocation() passing in NewLocation
	//SetActorLocation(NewLocation);

}

 

