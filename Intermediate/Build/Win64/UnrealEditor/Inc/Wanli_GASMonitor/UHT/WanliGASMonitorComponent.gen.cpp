// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WanliGASMonitorComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWanliGASMonitorComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Wanli_GASMonitor();
WANLI_GASMONITOR_API UClass* Z_Construct_UClass_UWanliGASMonitorComponent();
WANLI_GASMONITOR_API UClass* Z_Construct_UClass_UWanliGASMonitorComponent_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UWanliGASMonitorComponent ************************************************
void UWanliGASMonitorComponent::StaticRegisterNativesUWanliGASMonitorComponent()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UWanliGASMonitorComponent;
UClass* UWanliGASMonitorComponent::GetPrivateStaticClass()
{
	using TClass = UWanliGASMonitorComponent;
	if (!Z_Registration_Info_UClass_UWanliGASMonitorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WanliGASMonitorComponent"),
			Z_Registration_Info_UClass_UWanliGASMonitorComponent.InnerSingleton,
			StaticRegisterNativesUWanliGASMonitorComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UWanliGASMonitorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UWanliGASMonitorComponent_NoRegister()
{
	return UWanliGASMonitorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UWanliGASMonitorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "GASMonitor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Attach to any Character (or Actor with an ASC) to monitor GAS ability\n * activations and failures in real time.\n */" },
#endif
		{ "IncludePath", "WanliGASMonitorComponent.h" },
		{ "ModuleRelativePath", "Public/WanliGASMonitorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attach to any Character (or Actor with an ASC) to monitor GAS ability\nactivations and failures in real time." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisplayGASInfo_MetaData[] = {
		{ "Category", "GAS Monitor" },
		{ "ModuleRelativePath", "Public/WanliGASMonitorComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bDisplayGASInfo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisplayGASInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWanliGASMonitorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UWanliGASMonitorComponent_Statics::NewProp_bDisplayGASInfo_SetBit(void* Obj)
{
	((UWanliGASMonitorComponent*)Obj)->bDisplayGASInfo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UWanliGASMonitorComponent_Statics::NewProp_bDisplayGASInfo = { "bDisplayGASInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UWanliGASMonitorComponent), &Z_Construct_UClass_UWanliGASMonitorComponent_Statics::NewProp_bDisplayGASInfo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisplayGASInfo_MetaData), NewProp_bDisplayGASInfo_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWanliGASMonitorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWanliGASMonitorComponent_Statics::NewProp_bDisplayGASInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWanliGASMonitorComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWanliGASMonitorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Wanli_GASMonitor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWanliGASMonitorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWanliGASMonitorComponent_Statics::ClassParams = {
	&UWanliGASMonitorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UWanliGASMonitorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UWanliGASMonitorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWanliGASMonitorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UWanliGASMonitorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWanliGASMonitorComponent()
{
	if (!Z_Registration_Info_UClass_UWanliGASMonitorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWanliGASMonitorComponent.OuterSingleton, Z_Construct_UClass_UWanliGASMonitorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWanliGASMonitorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWanliGASMonitorComponent);
UWanliGASMonitorComponent::~UWanliGASMonitorComponent() {}
// ********** End Class UWanliGASMonitorComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_lukeo_Documents_Unreal_Projects_Sekiro_ATS_UAF_GAS_Plugins_Wanli_GASMonitor_Source_Wanli_GASMonitor_Public_WanliGASMonitorComponent_h__Script_Wanli_GASMonitor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWanliGASMonitorComponent, UWanliGASMonitorComponent::StaticClass, TEXT("UWanliGASMonitorComponent"), &Z_Registration_Info_UClass_UWanliGASMonitorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWanliGASMonitorComponent), 3606124798U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_lukeo_Documents_Unreal_Projects_Sekiro_ATS_UAF_GAS_Plugins_Wanli_GASMonitor_Source_Wanli_GASMonitor_Public_WanliGASMonitorComponent_h__Script_Wanli_GASMonitor_3345590258(TEXT("/Script/Wanli_GASMonitor"),
	Z_CompiledInDeferFile_FID_Users_lukeo_Documents_Unreal_Projects_Sekiro_ATS_UAF_GAS_Plugins_Wanli_GASMonitor_Source_Wanli_GASMonitor_Public_WanliGASMonitorComponent_h__Script_Wanli_GASMonitor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_lukeo_Documents_Unreal_Projects_Sekiro_ATS_UAF_GAS_Plugins_Wanli_GASMonitor_Source_Wanli_GASMonitor_Public_WanliGASMonitorComponent_h__Script_Wanli_GASMonitor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
