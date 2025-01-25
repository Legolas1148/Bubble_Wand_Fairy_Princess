// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Bubble_Wand/Bubble_WandGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBubble_WandGameMode() {}

// Begin Cross Module References
BUBBLE_WAND_API UClass* Z_Construct_UClass_ABubble_WandGameMode();
BUBBLE_WAND_API UClass* Z_Construct_UClass_ABubble_WandGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Bubble_Wand();
// End Cross Module References

// Begin Class ABubble_WandGameMode
void ABubble_WandGameMode::StaticRegisterNativesABubble_WandGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABubble_WandGameMode);
UClass* Z_Construct_UClass_ABubble_WandGameMode_NoRegister()
{
	return ABubble_WandGameMode::StaticClass();
}
struct Z_Construct_UClass_ABubble_WandGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Bubble_WandGameMode.h" },
		{ "ModuleRelativePath", "Bubble_WandGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABubble_WandGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABubble_WandGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Bubble_Wand,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABubble_WandGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABubble_WandGameMode_Statics::ClassParams = {
	&ABubble_WandGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABubble_WandGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ABubble_WandGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABubble_WandGameMode()
{
	if (!Z_Registration_Info_UClass_ABubble_WandGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABubble_WandGameMode.OuterSingleton, Z_Construct_UClass_ABubble_WandGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABubble_WandGameMode.OuterSingleton;
}
template<> BUBBLE_WAND_API UClass* StaticClass<ABubble_WandGameMode>()
{
	return ABubble_WandGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABubble_WandGameMode);
ABubble_WandGameMode::~ABubble_WandGameMode() {}
// End Class ABubble_WandGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_Bubble_Wand_Fairy_Princess_Bubble_Wand_Source_Bubble_Wand_Bubble_WandGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABubble_WandGameMode, ABubble_WandGameMode::StaticClass, TEXT("ABubble_WandGameMode"), &Z_Registration_Info_UClass_ABubble_WandGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABubble_WandGameMode), 497773864U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Bubble_Wand_Fairy_Princess_Bubble_Wand_Source_Bubble_Wand_Bubble_WandGameMode_h_2974514299(TEXT("/Script/Bubble_Wand"),
	Z_CompiledInDeferFile_FID_Projects_Bubble_Wand_Fairy_Princess_Bubble_Wand_Source_Bubble_Wand_Bubble_WandGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Bubble_Wand_Fairy_Princess_Bubble_Wand_Source_Bubble_Wand_Bubble_WandGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
