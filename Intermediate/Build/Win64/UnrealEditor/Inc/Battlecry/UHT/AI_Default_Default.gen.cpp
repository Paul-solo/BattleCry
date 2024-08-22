// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battlecry/Public/AI_Default_Default.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAI_Default_Default() {}
// Cross Module References
	BATTLECRY_API UClass* Z_Construct_UClass_AAI_Default_Default();
	BATTLECRY_API UClass* Z_Construct_UClass_AAI_Default_Default_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Battlecry();
// End Cross Module References
	void AAI_Default_Default::StaticRegisterNativesAAI_Default_Default()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAI_Default_Default);
	UClass* Z_Construct_UClass_AAI_Default_Default_NoRegister()
	{
		return AAI_Default_Default::StaticClass();
	}
	struct Z_Construct_UClass_AAI_Default_Default_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAI_Default_Default_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Battlecry,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAI_Default_Default_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAI_Default_Default_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AI_Default_Default.h" },
		{ "ModuleRelativePath", "Public/AI_Default_Default.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAI_Default_Default_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAI_Default_Default>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAI_Default_Default_Statics::ClassParams = {
		&AAI_Default_Default::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAI_Default_Default_Statics::Class_MetaDataParams), Z_Construct_UClass_AAI_Default_Default_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AAI_Default_Default()
	{
		if (!Z_Registration_Info_UClass_AAI_Default_Default.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAI_Default_Default.OuterSingleton, Z_Construct_UClass_AAI_Default_Default_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAI_Default_Default.OuterSingleton;
	}
	template<> BATTLECRY_API UClass* StaticClass<AAI_Default_Default>()
	{
		return AAI_Default_Default::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAI_Default_Default);
	AAI_Default_Default::~AAI_Default_Default() {}
	struct Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_AI_Default_Default_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_AI_Default_Default_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAI_Default_Default, AAI_Default_Default::StaticClass, TEXT("AAI_Default_Default"), &Z_Registration_Info_UClass_AAI_Default_Default, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAI_Default_Default), 215785589U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_AI_Default_Default_h_1953173721(TEXT("/Script/Battlecry"),
		Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_AI_Default_Default_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_paula_Documents_programering_BattleCry_Source_Battlecry_Public_AI_Default_Default_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
