// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BallPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BALLPLATFORMER_CPP_BallPlayerController_generated_h
#error "BallPlayerController.generated.h already included, missing '#pragma once' in BallPlayerController.h"
#endif
#define BALLPLATFORMER_CPP_BallPlayerController_generated_h

#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABallPlayerController(); \
	friend struct Z_Construct_UClass_ABallPlayerController_Statics; \
public: \
	DECLARE_CLASS(ABallPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BallPlatformer_Cpp"), NO_API) \
	DECLARE_SERIALIZER(ABallPlayerController)


#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABallPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABallPlayerController(ABallPlayerController&&); \
	ABallPlayerController(const ABallPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABallPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABallPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABallPlayerController) \
	NO_API virtual ~ABallPlayerController();


#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_12_PROLOG
#define FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BALLPLATFORMER_CPP_API UClass* StaticClass<class ABallPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
