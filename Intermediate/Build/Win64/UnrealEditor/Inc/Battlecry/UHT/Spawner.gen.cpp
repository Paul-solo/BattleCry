// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battlecry/Spawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawner() {}
// Cross Module References
	BATTLECRY_API UClass* Z_Construct_UClass_ASpawner();
	BATTLECRY_API UClass* Z_Construct_UClass_ASpawner_NoRegister();
	BATTLECRY_API UEnum* Z_Construct_UEnum_Battlecry_EEnemyType();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Battlecry();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEnemyType;
	static UEnum* EEnemyType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EEnemyType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EEnemyType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Battlecry_EEnemyType, (UObject*)Z_Construct_UPackage__Script_Battlecry(), TEXT("EEnemyType"));
		}
		return Z_Registration_Info_UEnum_EEnemyType.OuterSingleton;
	}
	template<> BATTLECRY_API UEnum* StaticEnum<EEnemyType>()
	{
		return EEnemyType_StaticEnum();
	}
	struct Z_Construct_UEnum_Battlecry_EEnemyType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enumerators[] = {
		{ "EEnemyType::EET_Zombie", (int64)EEnemyType::EET_Zombie },
		{ "EEnemyType::EET_Skeletol", (int64)EEnemyType::EET_Skeletol },
		{ "EEnemyType::EET_Tank", (int64)EEnemyType::EET_Tank },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enum_MetaDataParams[] = {
		{ "EET_Skeletol.Name", "EEnemyType::EET_Skeletol" },
		{ "EET_Tank.Name", "EEnemyType::EET_Tank" },
		{ "EET_Zombie.Name", "EEnemyType::EET_Zombie" },
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Battlecry_EEnemyType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Battlecry,
		nullptr,
		"EEnemyType",
		"EEnemyType",
		Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Battlecry_EEnemyType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_Battlecry_EEnemyType()
	{
		if (!Z_Registration_Info_UEnum_EEnemyType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEnemyType.InnerSingleton, Z_Construct_UEnum_Battlecry_EEnemyType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EEnemyType.InnerSingleton;
	}
	DEFINE_FUNCTION(ASpawner::execSpawn)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Wave);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Spawn(Z_Param_Wave);
		P_NATIVE_END;
	}
	void ASpawner::StaticRegisterNativesASpawner()
	{
		UClass* Class = ASpawner::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Spawn", &ASpawner::execSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASpawner_Spawn_Statics
	{
		struct Spawner_eventSpawn_Parms
		{
			int32 Wave;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Wave;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASpawner_Spawn_Statics::NewProp_Wave = { "Wave", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Spawner_eventSpawn_Parms, Wave), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpawner_Spawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpawner_Spawn_Statics::NewProp_Wave,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpawner_Spawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpawner_Spawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpawner, nullptr, "Spawn", nullptr, nullptr, Z_Construct_UFunction_ASpawner_Spawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawner_Spawn_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASpawner_Spawn_Statics::Spawner_eventSpawn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawner_Spawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASpawner_Spawn_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawner_Spawn_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ASpawner_Spawn_Statics::Spawner_eventSpawn_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ASpawner_Spawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpawner_Spawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpawner);
	UClass* Z_Construct_UClass_ASpawner_NoRegister()
	{
		return ASpawner::StaticClass();
	}
	struct Z_Construct_UClass_ASpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyClass;
		static const UECodeGen_Private::FBytePropertyParams NewProp_EnemyType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_EnemyType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpawns_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSpawns;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Battlecry,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ASpawner_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpawner_Spawn, "Spawn" }, // 1120318572
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Spawner.h" },
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyClass_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyClass = { "EnemyClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawner, EnemyClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyClass_MetaData), Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyClass_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType = { "EnemyType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawner, EnemyType), Z_Construct_UEnum_Battlecry_EEnemyType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType_MetaData), Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType_MetaData) }; // 197595853
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawner_Statics::NewProp_MaxSpawns_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "Spawner.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASpawner_Statics::NewProp_MaxSpawns = { "MaxSpawns", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpawner, MaxSpawns), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::NewProp_MaxSpawns_MetaData), Z_Construct_UClass_ASpawner_Statics::NewProp_MaxSpawns_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpawner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawner_Statics::NewProp_EnemyType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawner_Statics::NewProp_MaxSpawns,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpawner>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpawner_Statics::ClassParams = {
		&ASpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASpawner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpawner_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpawner_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASpawner()
	{
		if (!Z_Registration_Info_UClass_ASpawner.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpawner.OuterSingleton, Z_Construct_UClass_ASpawner_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASpawner.OuterSingleton;
	}
	template<> BATTLECRY_API UClass* StaticClass<ASpawner>()
	{
		return ASpawner::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawner);
	ASpawner::~ASpawner() {}
	struct Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::EnumInfo[] = {
		{ EEnemyType_StaticEnum, TEXT("EEnemyType"), &Z_Registration_Info_UEnum_EEnemyType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 197595853U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASpawner, ASpawner::StaticClass, TEXT("ASpawner"), &Z_Registration_Info_UClass_ASpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpawner), 1745949899U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_1559245548(TEXT("/Script/Battlecry"),
		Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
