// Fill out your copyright notice in the Description page of Project Settings.


#include "ATEBall.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
//Adds Dynamic??
#include "Components/ArrowComponent.h"


// Sets default values

AATEBall::AATEBall() :
	m_Speed(50)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   
    //USphereComponent - Collision box
    CollisionSphere = CreateDefaultSubobject<USphereComponent>("Sphere Component");
    CollisionSphere->SetSphereRadius(4.0f);//Might change later

    CollisionSphere->SetCollisionProfileName("BlockAll");

    
    //CollisionSphere->SetNotifyRigidBodyCollision(true); 
    CollisionSphere->OnComponentHit.AddDynamic(this, &AATEBall::OnHit);
    SetRootComponent(CollisionSphere);

    //UPaperSpriteComponent - Ball sprite ex soccer ball from UEModes lab
    SpriteBall = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite Ball");
    SpriteBall->SetupAttachment(RootComponent);
    SpriteBall->SetCollisionProfileName("NoCollision");
    //SpriteBall->SetRelativeLocation(FVector(-0.f, 0.f, 0.f));

    //UProjectileMovementComponent : Ball bounce
    BallMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Ball Movement Component");
    BallMovementComponent->SetUpdatedComponent(CollisionSphere);
    //Those are UProjectileMovementComponent variables
    BallMovementComponent->InitialSpeed = 500.0f;
    BallMovementComponent->MaxSpeed = 1000.0f;
    BallMovementComponent->bRotationFollowsVelocity = false;
    BallMovementComponent->bShouldBounce = true;
    BallMovementComponent->Bounciness = 10.1f;
    BallMovementComponent->ProjectileGravityScale = 0.0f;
    BallMovementComponent->Friction = 0.0f;
  
   
  

    //Where the initial start of the ball
    InitialPosition = GetActorLocation();
    Start();


}

void AATEBall::StartingDirection(FVector direction)
{
    FVector(-0.f, 0.f, 0.f);
    //I could randomize the ball spawn
    //IF SMT 
    //ELSE
}

bool AATEBall::IsActorActive()
{
	return IsActive;//false
}

void AATEBall::Start()
{

}

// Called when the game starts or when spawned
void AATEBall::BeginPlay()
{
	Super::BeginPlay();
   // BallMovementComponent->Velocity = FVector(-0.307107, 0, -0.307107) * BallMovementComponent->InitialSpeed;
	
}

// Called every frame
void AATEBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector pos = GetActorLocation();
    pos.Y = 0.1f;
    SetActorLocation(pos);

}

void AATEBall::Destroyed()
{
    Super::Destroyed();
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("BALL DESTROYED")));
}

UPrimitiveComponent* AATEBall::GetPhysicsComponent()
{
    return Cast<UPrimitiveComponent>(CollisionSphere);
}

void AATEBall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor != this)
    {
        if (GEngine)
        {
            //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has Hit"), *OtherActor->GetName()));
        }
    }
}

