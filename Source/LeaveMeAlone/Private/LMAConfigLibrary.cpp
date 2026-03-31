// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "LMAConfigLibrary.h"
#include "Engine/Engine.h"

//Игровые цели
int32 ULMAConfigLibrary::GetTotalShields()
{
	int32 Value = 3; // значение по умолчанию
	GConfig->GetInt(TEXT("LeaveMeAlone"), TEXT("TotalShields"), Value, GGameIni);
	return Value;
}

int32 ULMAConfigLibrary::GetTotalKeyCards()
{
	int32 Value = 5;
	GConfig->GetInt(TEXT("LeaveMeAlone"), TEXT("TotalKeyCards"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetRequiredEvacuationTime()
{
	float Value = 5.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("RequiredEvacuationTime"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetKeyCardTTL()
{
	float Value = 30.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("KeyCardTTL"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetKeyCardRespawnDelay()
{
	float Value = 15.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("KeyCardRespawnDelay"), Value, GGameIni);
	return Value;
}


//Выносливость игрока
float ULMAConfigLibrary::GetMaxStamina()
{
	float Value = 100.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("MaxStamina"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetSprintStaminaDrainRate()
{
	float Value = 15.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("SprintStaminaDrainRate"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetStaminaRegenRate()
{
	float Value = 10.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("StaminaRegenRate"), Value, GGameIni);
	return Value;
}


//Усиленный враг
float ULMAConfigLibrary::GetEnhancedEnemyHealthMultiplier()
{
	float Value = 2.5f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("EnhancedEnemyHealthMultiplier"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetEnhancedEnemyDamageMultiplier()
{
	float Value = 2.0f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("EnhancedEnemyDamageMultiplier"), Value, GGameIni);
	return Value;
}

float ULMAConfigLibrary::GetEnhancedEnemySpeedMultiplier()
{
	float Value = 1.3f;
	GConfig->GetFloat(TEXT("LeaveMeAlone"), TEXT("EnhancedEnemySpeedMultiplier"), Value, GGameIni);
	return Value;
}
