// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallPlatformer_Cpp/BallPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallPlayer() {}

// Begin Cross Module References
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_ABallPlayer();
BALLPLATFORMER_CPP_API UClass* Z_Construct_UClass_ABallPlayer_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BallPlatformer_Cpp();
// End Cross Module References

// Begin Class ABallPlayer
void ABallPlayer::StaticRegisterNativesABallPlayer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABallPlayer);
UClass* Z_Construct_UClass_ABallPlayer_NoRegister()
{
	return ABallPlayer::StaticClass();
}
struct Z_Construct_UClass_ABallPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "BallPlayer.h" },
		{ "ModuleRelativePath", "BallPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BallMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BallPlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BallMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallPlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABallPlayer_Statics::NewProp_BallMesh = { "BallMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABallPlayer, BallMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BallMesh_MetaData), NewProp_BallMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABallPlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallPlayer_Statics::NewProp_BallMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABallPlayer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_BallPlatformer_Cpp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABallPlayer_Statics::ClassParams = {
	&ABallPlayer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABallPlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABallPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_ABallPlayer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABallPlayer()
{
	if (!Z_Registration_Info_UClass_ABallPlayer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABallPlayer.OuterSingleton, Z_Construct_UClass_ABallPlayer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABallPlayer.OuterSingleton;
}
template<> BALLPLATFORMER_CPP_API UClass* StaticClass<ABallPlayer>()
{
	return ABallPlayer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABallPlayer);
ABallPlayer::~ABallPlayer() {}
// End Class ABallPlayer

// Begin Registration
struct Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABallPlayer, ABallPlayer::StaticClass, TEXT("ABallPlayer"), &Z_Registration_Info_UClass_ABallPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABallPlayer), 1090095222U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayer_h_3724411871(TEXT("/Script/BallPlatformer_Cpp"),
	Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BallPlatformer_Cpp_Source_BallPlatformer_Cpp_BallPlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
