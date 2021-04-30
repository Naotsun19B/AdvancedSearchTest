// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TestDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDSEARCHTEST_API UTestDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	// UObject interface.
	virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;
	// End of UObject interface.
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName CharacterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 TeamId;
};
