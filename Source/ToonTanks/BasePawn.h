// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//Es importante que las variables miembro sean privadas porque no queremos que se puedan modificar desde fuera de la clase
	//esto es una buena práctica de programación, ya que si se modifican desde fuera de la clase, se pueden producir errores
	//y comportamientos inesperados,tales como que el valor de la variable miembro no sea el esperado o que se modifique sin querer
	// Components

	//Usaremos punteros para la mayoria de nuestras variables siempre que no sean tipos base, como int, float, double, etc.
	//Esto debido a que los punteros son livianos, son solo direcciones de memoria, y no ocupan mucho espacio en memoria
	//y nos permiten trabajar con objetos que se crean en tiempo de ejecución, Y PERMITEN SER EFICIENTES EN MEMORIA
	UPROPERTY()
	class UCapsuleComponent* capsuleComp;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase

	UPROPERTY()
	UStaticMeshComponent* baseMesh;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase
	UPROPERTY()
	UStaticMeshComponent* turretMesh;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase
	UPROPERTY()
	USceneComponent* projectileSpawnPoint;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
