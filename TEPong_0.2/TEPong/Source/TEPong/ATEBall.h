// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ATEBall.generated.h"

UCLASS()
class TEPONG_API AATEBall : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AATEBall();
    UPROPERTY(EditAnywhere, Category = "Category scene")
        class USceneComponent* SceneComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sphere Component")
        class USphereComponent* CollisionSphere;



    UPROPERTY(EditAnywhere, Category = "Sprite Ball")
        class UPaperSpriteComponent* SpriteBall;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ball Movement Component")
        class UProjectileMovementComponent* BallMovementComponent;

    void StartingDirection(FVector direction);

    bool IsActorActive();

    void Start();




protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    //virtual void Destroyed() override;

    class UPrimitiveComponent* GetPhysicsComponent();

private:

    UFUNCTION()
        void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

    FVector MovementDirection;

    UPROPERTY(EditAnywhere)
        float m_Speed;

    bool IsActive = false;

    FVector InitialPosition;

};
