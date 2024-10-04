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
	
	
	UPROPERTY(VisibleInstanceOnly)	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	int32 VisibleInstanceOnlyInt = 12;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12

	UPROPERTY(EditAnywhere, BlueprintReadWrite)	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	FVector InstancePosition;

	UPROPERTY(VisibleDefaultsOnly)	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	int32 VisibleDefaultOnlyInt = 12;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12

	UPROPERTY(EditDefaultsOnly)	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	int32 EditDefaultsOnlyInt = 2;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12

	UPROPERTY(EditInstanceOnly)	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	int32 EditInstanceOnlyInt = 3;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12

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
	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
		//Variables miembro de la clase
	class UCapsuleComponent* capsuleComp;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Components",meta = (AllowPrivateAccess = "true"))	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
		//Variables miembro de la clase
	UStaticMeshComponent* baseMesh;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase
	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite,meta = (AllowPrivateAccess = "true"))	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
		//Variables miembro de la clase
	UStaticMeshComponent* turretMesh;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase
	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
		//Variables miembro de la clase
	USceneComponent* projectileSpawnPoint;	//Declaración directa de clase, no se necesita incluir el archivo de cabecera de la clase, solo estamos declarando la clase

	// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Base Pawn Variables", meta = (AllowPrivateAccess = "true"))	//meta es una macro que se usa para definir metadatos de la variable miembro de la clase
		//Variables miembro de la clase
	int32 VisibleAnywhereInt = 12;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Base Pawn Variables",meta = (AllowPrivateAccess = "true"))	//Macro para declarar una variable miembro de la clase, visible en el editor de propiedades, solo lectura, y en la categoría "Componentes"
	int32 EditAnywhereInt = 12;	//Variable miembro de la clase, visible en el editor de propiedades, de tipo entero de 32 bits, con un valor inicial de 12



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
