// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LMAConfigLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LEAVEMEALONE_API ULMAConfigLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:


	/*Игровые цели.*/
	UFUNCTION(BlueprintCallable, Category = "Config")
	static int32 GetTotalShields();

	UFUNCTION(BlueprintCallable, Category = "Config")
	static int32 GetTotalKeyCards();

	UFUNCTION(BlueprintCallable, Category = "Config")
	static float GetRequiredEvacuationTime();

	UFUNCTION(BlueprintCallable, Category = "Config")
	static float GetKeyCardTTL();

	UFUNCTION(BlueprintCallable, Category = "Config")
	static float GetKeyCardRespawnDelay();

	//Выносливость игрока.
	 UFUNCTION(BlueprintCallable, Category = "Config|Stamina")
	static float GetMaxStamina();

	UFUNCTION(BlueprintCallable, Category = "Config|Stamina")
	static float GetSprintStaminaDrainRate();

	UFUNCTION(BlueprintCallable, Category = "Config|Stamina")
	static float GetStaminaRegenRate();


	//Усиленный враг
	UFUNCTION(BlueprintCallable, Category = "Config|EnhancedEnemy")
	static float GetEnhancedEnemyHealthMultiplier();

	UFUNCTION(BlueprintCallable, Category = "Config|EnhancedEnemy")
	static float GetEnhancedEnemyDamageMultiplier();

	UFUNCTION(BlueprintCallable, Category = "Config|EnhancedEnemy")
	static float GetEnhancedEnemySpeedMultiplier();

};
