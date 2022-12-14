// Fill out your copyright notice in the Description page of Project Settings.

//#include "ATEBall.h"
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
    //PlayerRootCollisionBox->SetCollisionProfileName("BlockAllDynamic");
    PlayerRootCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //PlayerRootCollisionBox->SetSimulatePhysics(true);
    //PlayerRootCollisionBox->SetEnableGravity(false);
    //PlayerRootCollisionBox->SetLinearDamping(1.0f);

    //PlayerRootCollisionBox->SetRelativeRotation(FRotator(0, 90.0f, 0));
    //PlayerRootCollisionBox->GetBodyInstance()->bLockRotation = true;// BodyInstance.bLockXRotation = true; SetConstraintMode(EDOFMode::XZPlane)
    PlayerRootCollisionBox->GetBodyInstance()->bLockXRotation = true;
    PlayerRootCollisionBox->GetBodyInstance()->bLockYRotation = true;
    PlayerRootCollisionBox->GetBodyInstance()->bLockZRotation = true;
    PlayerRootCollisionBox->GetBodyInstance()->bLockYTranslation = true;
    PlayerRootCollisionBox->GetBodyInstance()->bLockXTranslation = true;
    PlayerRootCollisionBox->SetBoxExtent(FVector(30, 30.0f, 138));
    //PlayerRootCollisionBox->SetRelativeRotation(FRotator(180, 90, 180));
    PlayerRootCollisionBox->SetRelativeRotation(FRotator(90, 0, 0));
    

    SetRootComponent(PlayerRootCollisionBox);
    //PlayerRootCollisionBox->SetWorldLocation(FVector(-400, 2.0f, 0));
    //PlayerRootCollisionBox->SetRelativeLocation(FVector(-400, 2.0f, 0));
    //PlayerRootCollisionBox->SetupAttachment(RootComponent);
    //isPlayer = false;

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
    //PawnSpriteComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PawnSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    m_BottomBorder = FVector((0.0f, 0.0f, -200.0f));
    m_TopBorder = FVector((0.0f, 0.0f, 200.0f));

}

// Called when the game starts or when spawned
void AATEPawn::BeginPlay()
{
    Super::BeginPlay();
    //if (isPlayer)
    //{
    //	
    //	//PawnSpriteComponent->SetRelativeRotation(FRotator(90, 0, 90));
    //	if (Sprite)
    //	{
    //		PawnSpriteComponent->SetSprite(Cast<UPaperSprite>(Sprite));
    //	}

    //	PlayerRootCollisionBox->SetRelativeLocation(FVector(-400, 2.0f, 0));
    //	PawnSpriteComponent->SetRelativeRotation(FRotator(90, 0, 90));

    //	//Box collision Extent
        //
    //	//PlayerRootCollisionBox->SetRelativeRotation(FRotator(180, 90, 180));
    //
    //}

    //SetDirection(FVector::UpVector); // temp might change that
}




void AATEPawn::moveUpandDown(float value)
{
    moveUpAndDown = value;

    //if (value > 0)
    //	SetDirection(1.0f);

    //if (value < 0)
    //	SetDirection(-1.0f);
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

//void AATEPawn::SetDirection(float Direction)
//{
//	/*CORE_API const FVector FVector::UpVector(0.0f, 0.0f, 1.0f);
//	CORE_API const FVector FVector::DownVector(0.0f, 0.0f, -1.0f);*/
//	m_Direction = FVector(0.0f, 0.0f, 0.0f);
//
//	if (Direction == 1.0f) {
//		//PawnSpriteComponent->SetRelativeRotation(FRotator(0, 0, 0));
//		
//		m_Direction = FVector(0.0f,0.0f,Direction);
//	}
//	else if (Direction == -1.0f) {
//		m_Direction = FVector(0.0f, 0.0f, Direction);
//	}
//	//SetActorLocation(GetActorLocation() + SetDirection * 5000.0f);
//}


// Called every frame
void AATEPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //FVector NewLocation = GetActorLocation();

    //SetActorLocation(pos);
    if (isPlayer)
    {
        //AI LOGIC GOES HERE 
        // Set the ball to the paddle if isplayer is false? Not sure
        //SetActorLocation("");
    }

    //if (!m_Direction.IsZero())
    //{
        //FVector NewLocation = GetActorLocation() + (moveUpAndDown * 200.0f * DeltaTime);
        //SetActorLocation(NewLocation);

    FVector Location = GetActorLocation();

    Location.Z += moveUpAndDown * DeltaTime * 200.0f;

    SetActorLocation(Location);




    //FVector OldLocation = GetActorLocation();
    //int x = 2;
}


/*FVector PaddlePos = GetActorLocation();

if (PaddlePos.Z < -200.0f)
{
    PaddlePos.Z = -PaddlePos.Z;
}
else if (PaddlePos.Z > 200.0f)
{
    PaddlePos.Z = -PaddlePos.Z;
}*/






