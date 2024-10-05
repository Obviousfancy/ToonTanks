// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
// Sets default values
ATank::ATank()
{
    PrimaryActorTick.bCanEverTick = true;

    springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));                          //Creamos el subobjeto SpringArmComponent
    springArmComp->SetupAttachment(RootComponent);                                                                    //Adjuntamos al RootComponent el SpringArm

    cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));                                    //Creamos el subobjeto UCmeraComponent
    cameraComp->SetupAttachment(springArmComp);                                                                         //Adjuntamos el objeto a el Spring Arm

}




void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
        Super::SetupPlayerInputComponent(PlayerInputComponent);															//Ponemos esta linea para no perder ninguna funcionalidad que este en la funcion padre, o version principal

		PlayerInputComponent->BindAxis(TEXT("MoveForward"), this,&ATank::Move);									//Hacemos un bind axis para poder movernos, con el  axis mappings MoveForward previamente predefinido, la instancia actual de ATank, y con la funcion miembro Move, como puntero
		
	
}

//Funcion para ejecutar el movimiento
void ATank::Move(float Value)
{

	FVector DeltaLocation = FVector::ZeroVector;																		//Creamos un vector en ceros
	DeltaLocation.X = Value * speed;																					//Le damos un valor en el eje X, al vector multiplicado por una velocidad
	AddActorLocalOffset(DeltaLocation);																					//Asignamos la cantidad de movimiento que se permite usar, por medio de la funcion AddActorLocalOffset
	
    
}
