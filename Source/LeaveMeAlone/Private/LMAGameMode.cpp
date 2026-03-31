// LeaveMeAlone Game by Netologiya. All RightsReserved.

#include "LMAGameMode.h"
#include "Engine/Engine.h"
#include "Player/LMADefaultCharacter.h"
#include "Player/LMAPlayerController.h"

ALMAGameMode::ALMAGameMode() 
{
	DefaultPawnClass = ALMADefaultCharacter::StaticClass();
	PlayerControllerClass = ALMAPlayerController::StaticClass();

	// Загружаем значения из INI
	LoadConfigValues();
}

void ALMAGameMode::LoadConfigValues()
{
	// Читаем значения из DefaultGame.ini
	// Секция [/Script/LeaveMeAlone.LMAGameMode]

	GConfig->GetInt(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("TotalShields"), TotalShields, GGameIni);

	GConfig->GetInt(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("TotalKeyCards"), TotalKeyCards, GGameIni);

	GConfig->GetFloat(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("RequiredEvacuationTime"), RequiredEvacuationTime, GGameIni);

	GConfig->GetFloat(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("KeyCardTTL"), KeyCardTTL, GGameIni);

	GConfig->GetFloat(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("KeyCardRespawnDelay"), KeyCardRespawnDelay, GGameIni);

	GConfig->GetInt(TEXT("/Script/LeaveMeAlone.LMAGameMode"), TEXT("KeyCardStartActiveCount"), KeyCardStartActiveCount, GGameIni);

	// Выводим в лог для проверки
	UE_LOG(LogTemp, Warning, TEXT("=== Загружены настройки из INI ==="));
	UE_LOG(LogTemp, Warning, TEXT("TotalShields: %d"), TotalShields);
	UE_LOG(LogTemp, Warning, TEXT("TotalKeyCards: %d"), TotalKeyCards);
	UE_LOG(LogTemp, Warning, TEXT("RequiredEvacuationTime: %.1f"), RequiredEvacuationTime);
	UE_LOG(LogTemp, Warning, TEXT("KeyCardTTL: %.1f"), KeyCardTTL);
}

void ALMAGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ALMAGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	LoadConfigValues(); // Перезагружаем при инициализации игры
}