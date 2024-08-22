// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Spawner.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTLECRY_Spawner_generated_h
#error "Spawner.generated.h already included, missing '#pragma once' in Spawner.h"
#endif
#define BATTLECRY_Spawner_generated_h

#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_SPARSE_DATA
#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSpawn);


#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_ACCESSORS
#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpawner(); \
	friend struct Z_Construct_UClass_ASpawner_Statics; \
public: \
	DECLARE_CLASS(ASpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Battlecry"), NO_API) \
	DECLARE_SERIALIZER(ASpawner)


#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpawner(ASpawner&&); \
	NO_API ASpawner(const ASpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpawner) \
	NO_API virtual ~ASpawner();


#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_15_PROLOG
#define FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_SPARSE_DATA \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_ACCESSORS \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BATTLECRY_API UClass* StaticClass<class ASpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_paula_Documents_Unreal_Projects_Battlecry_Source_Battlecry_Spawner_h


#define FOREACH_ENUM_EENEMYTYPE(op) \
	op(EEnemyType::EET_Zombie) \
	op(EEnemyType::EET_Skeletol) \
	op(EEnemyType::EET_Tank) 

enum class EEnemyType : uint8;
template<> struct TIsUEnumClass<EEnemyType> { enum { Value = true }; };
template<> BATTLECRY_API UEnum* StaticEnum<EEnemyType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
