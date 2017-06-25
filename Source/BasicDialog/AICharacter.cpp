// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(FName("BoxComp"));
	BoxComp->SetupAttachment(RootComponent);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(FName("AudioComp"));
	AudioComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	// Register begin and end overlap functions
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AAICharacter::OnBoxOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &AAICharacter::OnBoxEndOverlap);
	
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharacter::OnBoxOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}


void AAICharacter::OnBoxEndOverlap(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AAICharacter::AnswerToCharacter(FName PlayerLine, TArray<FSubtitle>& SubtitleToDisplay, float delay)
{
	// TODO implement it
}