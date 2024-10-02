// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"		//Incluimos el archivo de cabecera de la clase CapsuleComponent para poder crear objetos
#include "Components/StaticMeshComponent.h"		//Incluimos el archivo de cabecera de la clase StaticMeshComponent para poder crear objetos
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));			//Creación de un componente de colisión de cápsula
	RootComponent = capsuleComp;		//Establecemos el componente de colisión de cápsula como el componente raíz del objeto

	//Creación de un componente de malla estática para la base del tanque
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));		//Creación de un componente de malla estática
	baseMesh->SetupAttachment(capsuleComp);		//Establecemos el componente de malla estática como hijo del componente de colisión de cápsula
	
	//Creación de un componente de malla estática para la torreta del tanque
	turretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));		//Creación de un componente de malla estática
	turretMesh->SetupAttachment(baseMesh);		//Establecemos el componente de malla estática como hijo del componente de malla estática de la base
	
	//Creación de un componente de escena para el punto de generación de proyectiles
	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));		//Creación de un componente de escena
	projectileSpawnPoint->SetupAttachment(turretMesh);		//Establecemos el componente de escena como hijo del componente de malla estática de la torreta
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

