///
/// NitroImageOnLoad.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "NitroImageOnLoad.hpp"

#include <jni.h>
#include <fbjni/fbjni.h>
#include <NitroModules/HybridObjectRegistry.hpp>

#include "JHybridImageSpec.hpp"
#include "JFunc_void_std__string.hpp"
#include "JHybridImageFactorySpec.hpp"
#include "JHybridTestObjectSwiftKotlinSpec.hpp"
#include "JFunc_void_std__vector_Powertrain_.hpp"
#include "JFunc_void.hpp"
#include "JFunc_void_std__optional_double_.hpp"
#include "JFunc_std__shared_ptr_Promise_double__.hpp"
#include "JFunc_std__shared_ptr_Promise_std__shared_ptr_Promise_double____.hpp"
#include "JFunc_std__shared_ptr_Promise_std__shared_ptr_Promise_std__shared_ptr_ArrayBuffer_____.hpp"
#include "JFunc_std__shared_ptr_Promise_std__string__.hpp"
#include "JHybridBaseSpec.hpp"
#include "JHybridChildSpec.hpp"
#include <NitroModules/JNISharedPtr.hpp>
#include <NitroModules/DefaultConstructableObject.hpp>
#include "HybridTestObjectCpp.hpp"

namespace margelo::nitro::image {

int initialize(JavaVM* vm) {
  using namespace margelo::nitro;
  using namespace margelo::nitro::image;
  using namespace facebook;

  return facebook::jni::initialize(vm, [] {
    // Register native JNI methods
    margelo::nitro::image::JHybridImageSpec::registerNatives();
    margelo::nitro::image::JFunc_void_std__string::registerNatives();
    margelo::nitro::image::JHybridImageFactorySpec::registerNatives();
    margelo::nitro::image::JHybridTestObjectSwiftKotlinSpec::registerNatives();
    margelo::nitro::image::JFunc_void_std__vector_Powertrain_::registerNatives();
    margelo::nitro::image::JFunc_void::registerNatives();
    margelo::nitro::image::JFunc_void::registerNatives();
    margelo::nitro::image::JFunc_void::registerNatives();
    margelo::nitro::image::JFunc_void::registerNatives();
    margelo::nitro::image::JFunc_void_std__optional_double_::registerNatives();
    margelo::nitro::image::JFunc_std__shared_ptr_Promise_double__::registerNatives();
    margelo::nitro::image::JFunc_std__shared_ptr_Promise_std__shared_ptr_Promise_double____::registerNatives();
    margelo::nitro::image::JFunc_std__shared_ptr_Promise_std__shared_ptr_Promise_std__shared_ptr_ArrayBuffer_____::registerNatives();
    margelo::nitro::image::JFunc_std__shared_ptr_Promise_double__::registerNatives();
    margelo::nitro::image::JFunc_std__shared_ptr_Promise_std__string__::registerNatives();
    margelo::nitro::image::JFunc_void_std__string::registerNatives();
    margelo::nitro::image::JHybridBaseSpec::registerNatives();
    margelo::nitro::image::JHybridChildSpec::registerNatives();

    // Register Nitro Hybrid Objects
    HybridObjectRegistry::registerHybridObjectConstructor(
      "ImageFactory",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridImageFactorySpec::javaobject> object("com/margelo/nitro/image/ImageFactory");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridImageFactorySpec>(globalRef);
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "TestObjectCpp",
      []() -> std::shared_ptr<HybridObject> {
        static_assert(std::is_default_constructible_v<HybridTestObjectCpp>,
                      "The HybridObject \"HybridTestObjectCpp\" is not default-constructible! "
                      "Create a public constructor that takes zero arguments to be able to autolink this HybridObject.");
        return std::make_shared<HybridTestObjectCpp>();
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "TestObjectSwiftKotlin",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridTestObjectSwiftKotlinSpec::javaobject> object("com/margelo/nitro/image/HybridTestObjectKotlin");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridTestObjectSwiftKotlinSpec>(globalRef);
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Base",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridBaseSpec::javaobject> object("com/margelo/nitro/image/HybridBase");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridBaseSpec>(globalRef);
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "Child",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridChildSpec::javaobject> object("com/margelo/nitro/image/HybridChild");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridChildSpec>(globalRef);
      }
    );
  });
}

} // namespace margelo::nitro::image
