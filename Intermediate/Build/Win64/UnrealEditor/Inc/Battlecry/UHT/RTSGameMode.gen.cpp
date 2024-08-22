// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battlecry/Public/RTSGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSGameMode() {}
// Cross Module References
	BATTLECRY_API UClass* Z_Construct_UClass_ARTSGameMode();
	BATTLECRY_API UClass* Z_Construct_UClass_ARTSGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_Battlecry();
// End Cross Module References
	void ARTSGameMode::StaticRegisterNativesARTSGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARTSGameMode);
	UClass* Z_Construct_UClass_ARTSGameMode_NoRegister()
	{
		return ARTSGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ARTSGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARTSGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_Battlecry,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARTSGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARTSGameMode_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RTSGameMode.h" },
		{ "ModuleRelativePath", "Public/RTSGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARTSGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARTSGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARTSGameMode_Statics::ClassParams = {
		&ARTSGameMode::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARTSGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARTSGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ARTSGameMode()
	{
		if (!Z_Registration_Info_UClass_ARTSGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARTSGameMode.OuterSingleton, Z_Construct_UClass_ARTSGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARTSGameMode.OuterSingleton;
	}
	template<> BATTLECRY_API UClass* StaticClass<ARTSGameMode>()
	{
		return ARTSGameMode::StaticClass();
	}
	ARTSGameMode::ARTSGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSGameMode);
	ARTSGameMode::~ARTSGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_RTSGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_RTSGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARTSGameMode, ARTSGameMode::StaticClass, TEXT("ARTSGameMode"), &Z_Registration_Info_UClass_ARTSGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARTSGameMode), 1110279938U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_RTSGameMode_h_1519782156(TEXT("/Script/Battlecry"),
		Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_RTSGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_RTSGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
