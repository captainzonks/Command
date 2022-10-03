// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComCamera.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class COMMAND_API AComCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AComCamera();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<USpringArmComponent> GetSpringArmComponent() { return SpringArm; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category="Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category="Components")
	TObjectPtr<UCameraComponent> Camera;
};
