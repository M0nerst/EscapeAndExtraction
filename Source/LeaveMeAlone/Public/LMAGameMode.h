// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LMAGameMode.generated.h"

/**
 *
 */
UCLASS()
class LEAVEMEALONE_API ALMAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALMAGameMode();

	// Цели уровня (читаются из INI)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 TotalShields = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 TotalKeyCards = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	float RequiredEvacuationTime = 5.0f;

	// Параметры ключей
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyCard")
	float KeyCardTTL = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyCard")
	float KeyCardRespawnDelay = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KeyCard")
	int32 KeyCardStartActiveCount = 2;

protected:
	virtual void BeginPlay() override;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	void LoadConfigValues();
};