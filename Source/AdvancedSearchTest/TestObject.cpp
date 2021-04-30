// Fill out your copyright notice in the Description page of Project Settings.

#include "TestObject.h"

void UTestObject::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
	Super::GetAssetRegistryTags(OutTags);

	FString ObjectCategoryString = FString(FName(NAME_None).ToString());
	{
		if (UEnum* EnumPtr = StaticEnum<EObjectCategory>())
		{
			ObjectCategoryString = EnumPtr->GetValueAsString(ObjectCategory);
		}	
	}
	
	// オブジェクトのカテゴリを追加.
	OutTags.Add(FAssetRegistryTag(
		GET_MEMBER_NAME_CHECKED(UTestObject, ObjectCategory),
		ObjectCategoryString,
		FAssetRegistryTag::ETagType::TT_Alphabetical,
		FAssetRegistryTag::ETagDisplay::TD_None
	));
	
	for (const auto& UserDefinedTag : UserDefinedTags)
	{
		const FAssetRegistryTag::ETagType TagType =
			UserDefinedTag.Value.IsNumeric() ?
			FAssetRegistryTag::ETagType::TT_Numerical :
			FAssetRegistryTag::ETagType::TT_Alphabetical;
		
		
		OutTags.Add(FAssetRegistryTag(
			UserDefinedTag.Key,
			UserDefinedTag.Value,
			TagType,
			FAssetRegistryTag::ETagDisplay::TD_None
		));
	}
}
