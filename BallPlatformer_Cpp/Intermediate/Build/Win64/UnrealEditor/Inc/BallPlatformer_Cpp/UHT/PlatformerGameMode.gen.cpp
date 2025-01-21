// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallPlatformer_Cpp/PlatformerGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlatformerGameMode() {}

// Begin Cross Module References
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_APlatformerGameMode();
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_APlatformerGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_BallPlatformer_Cpp();
// End Cross Module References

// Begin Class APlatformerGameMode
void APlatformerGameMode::StaticRegisterNativesAPlatformerGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlatformerGameMode);
UClass* Z_Construct_UClass_APlatformerGameMode_NoRegister()
{
	return APlatformerGameMode::StaticClass();
}
struct Z_Construct_UClass_APlatformerGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "PlatformerGameMode.h" },
		{ "ModuleRelativePath", "PlatformerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlatformerGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APlatformerGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_BallPlatformer_Cpp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlatformerGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlatformerGameMode_Statics::ClassParams = {
	&APlatformerGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlatformerGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APlatformerGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlatformerGameMode()
{
	if (!Z_Registration_Info_UClass_APlatformerGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlatformerGameMode.OuterSingleton, Z_Construct_UClass_APlatformerGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlatformerGameMode.OuterSingleton;
}
template<> BALLPLATFORMER_CPP_API UClass* StaticClass<APlatformerGameMode>()
{
	return APlatformerGameMode::StaticClass();
}
APlatformerGameMode::APlatformerGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlatformerGameMode);
APlatformerGameMode::~APlatformerGameMode() {}
// End Class APlatformerGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlatformerGameMode, APlatformerGameMode::StaticClass, TEXT("APlatformerGameMode"), &Z_Registration_Info_UClass_APlatformerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlatformerGameMode), 1582281777U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_1842902272(TEXT("/Script/BallPlatformer_Cpp"),
	Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_PlatformerGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
