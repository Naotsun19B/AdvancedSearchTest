// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestObject.generated.h"

UENUM()
enum class EObjectCategory : uint8
{
	Door,
	Wall,
	Floor,
};

/**
 * 
 */
UCLASS(Blueprintable)
class ADVANCEDSEARCHTEST_API UTestObject : public UObject
{
	GENERATED_BODY()

public:
	// UObject interface.
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
	// End of UObject interface.
	
private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FName, FString> UserDefinedTags;

	UPROPERTY(EditDefaultsOnly)
	EObjectCategory ObjectCategory;
};
