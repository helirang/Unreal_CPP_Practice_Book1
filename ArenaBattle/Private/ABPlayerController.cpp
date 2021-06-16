// Fill out your copyright notice in the Description page of Project Settings.

#include "ABPlayerController.h"
#include "ABHUDWidget.h"
#include "ABPlayerState.h"

AABPlayerController::AABPlayerController()
{
	static ConstructorHelpers::FClassFinder<UABHUDWidget> UI_HUD_C(TEXT("/Game/Book/UI/UI_HUD.UI_HUD_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::Possess(APawn* aPawn)
{
	ABLOG_S(Warning);
	Super::Possess(aPawn);
}

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	FInputModeGameOnly InputMode; //게임 테스트 편의를 위한 ui배제 p.158
	SetInputMode(InputMode);

	HUDWidget = CreateWidget<UABHUDWidget>(this, HUDWidgetClass);
	HUDWidget->AddToViewport();

	auto ABPlayerState = Cast<AABPlayerState>(PlayerState);
	ABCHECK(nullptr != ABPlayerState);
	HUDWidget->BindPlayerState(ABPlayerState);
	ABPlayerState->OnPlayerStateChanged.Broadcast();
}

UABHUDWidget* AABPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}



