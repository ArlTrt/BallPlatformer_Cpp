// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallPlatformer_Cpp/BallPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallPlayerController() {}

// Begin Cross Module References
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_ABallPlayerController();
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_ABallPlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_BallPlatformer_Cpp();
// End Cross Module References

// Begin Class ABallPlayerController
void ABallPlayerController::StaticRegisterNativesABallPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABallPlayerController);
UClass* Z_Construct_UClass_ABallPlayerController_NoRegister()
{
	return ABallPlayerController::StaticClass();
}
struct Z_Construct_UClass_ABallPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "BallPlayerController.h" },
		{ "ModuleRelativePath", "BallPlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABallPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_BallPlatformer_Cpp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABallPlayerController_Statics::ClassParams = {
	&ABallPlayerController::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABallPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABallPlayerController()
{
	if (!Z_Registration_Info_UClass_ABallPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABallPlayerController.OuterSingleton, Z_Construct_UClass_ABallPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABallPlayerController.OuterSingleton;
}
template<> BALLPLATFORMER_CPP_API UClass* StaticClass<ABallPlayerController>()
{
	return ABallPlayerController::StaticClass();
}
ABallPlayerController::ABallPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABallPlayerController);
ABallPlayerController::~ABallPlayerController() {}
// End Class ABallPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABallPlayerController, ABallPlayerController::StaticClass, TEXT("ABallPlayerController"), &Z_Registration_Info_UClass_ABallPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABallPlayerController), 1744477435U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_283998163(TEXT("/Script/BallPlatformer_Cpp"),
	Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
