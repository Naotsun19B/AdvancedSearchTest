// Fill out your copyright notice in the Description page of Project Settings.

#include "TestDataAsset.h"

void UTestDataAsset::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	Super::GetAssetRegistryTags(OutTags);

	// キャラの名前を追加.
	OutTags.Add(FAssetRegistryTag(
		GET_MEMBER_NAME_CHECKED(UTestDataAsset, CharacterName),
		CharacterName.ToString(),
		FAssetRegistryTag::ETagType::TT_Alphabetical,
		FAssetRegistryTag::ETagDisplay::TD_None
	));
	
	// チームIDを追加.
	OutTags.Add(FAssetRegistryTag(
		GET_MEMBER_NAME_CHECKED(UTestDataAsset, TeamId),
		FString::FromInt(TeamId),
		FAssetRegistryTag::ETagType::TT_Numerical,
		FAssetRegistryTag::ETagDisplay::TD_None
	));
}
