// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ComPlayerController.generated.h"

class AComCamera;
/**
 * 
 */
UCLASS()
class COMMAND_API AComPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AComPlayerController();
	
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:

	void Zoom(float AxisValue);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess), Category = "Config")
	TObjectPtr<AComCamera> ComCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "Config")
	float ZoomFactor{5.f};
};
