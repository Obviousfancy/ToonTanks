// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	public:
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;						//Copiamos del Base Pawn para poder tener un player input

	private:

	UPROPERTY(EditAnywhere)
	float speed;
	
	
	UPROPERTY(VisibleAnywhere,Category = "Components")
	class UCameraComponent* cameraComp;																//Componente apuntador de tipo UCameraComponent

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* springArmComp;														//Componente apuntodor de tipo USpringArmComponent para colocar la camara

	void Move(float Value);
};
