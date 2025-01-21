// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlatformerGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BALLPLATFORMER_CPP_PlatformerGameMode_generated_h
#error "PlatformerGameMode.generated.h already included, missing '#pragma once' in PlatformerGameMode.h"
#endif
#define BALLPLATFORMER_CPP_PlatformerGameMode_generated_h

#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlatformerGameMode(); \
	friend struct Z_Construct_UClass_APlatformerGameMode_Statics; \
public: \
	DECLARE_CLASS(APlatformerGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/BallPlatformer_Cpp"), NO_API) \
	DECLARE_SERIALIZER(APlatformerGameMode)


#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlatformerGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APlatformerGameMode(APlatformerGameMode&&); \
	APlatformerGameMode(const APlatformerGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlatformerGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlatformerGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlatformerGameMode) \
	NO_API virtual ~APlatformerGameMode();


#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_12_PROLOG
#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BALLPLATFORMER_CPP_API UClass* StaticClass<class APlatformerGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
