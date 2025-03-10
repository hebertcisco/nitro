///
/// JHybridImageFactorySpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "JHybridImageFactorySpec.hpp"

// Forward declaration of `HybridImageSpec` to properly resolve imports.
namespace margelo::nitro::image { class HybridImageSpec; }

#include <memory>
#include "HybridImageSpec.hpp"
#include "JHybridImageSpec.hpp"
#include <NitroModules/JNISharedPtr.hpp>
#include <string>

namespace margelo::nitro::image {

  jni::local_ref<JHybridImageFactorySpec::jhybriddata> JHybridImageFactorySpec::initHybrid(jni::alias_ref<jhybridobject> jThis) {
    return makeCxxInstance(jThis);
  }

  void JHybridImageFactorySpec::registerNatives() {
    registerHybrid({
      makeNativeMethod("initHybrid", JHybridImageFactorySpec::initHybrid),
    });
  }

  size_t JHybridImageFactorySpec::getExternalMemorySize() noexcept {
    static const auto method = javaClassStatic()->getMethod<jlong()>("getMemorySize");
    return method(_javaPart);
  }

  // Properties
  

  // Methods
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromFile(const std::string& path) {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JHybridImageSpec::javaobject>(jni::alias_ref<jni::JString> /* path */)>("loadImageFromFile");
    auto __result = method(_javaPart, jni::make_jstring(path));
    return JNISharedPtr::make_shared_from_jni<JHybridImageSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromURL(const std::string& path) {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JHybridImageSpec::javaobject>(jni::alias_ref<jni::JString> /* path */)>("loadImageFromURL");
    auto __result = method(_javaPart, jni::make_jstring(path));
    return JNISharedPtr::make_shared_from_jni<JHybridImageSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::loadImageFromSystemName(const std::string& path) {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JHybridImageSpec::javaobject>(jni::alias_ref<jni::JString> /* path */)>("loadImageFromSystemName");
    auto __result = method(_javaPart, jni::make_jstring(path));
    return JNISharedPtr::make_shared_from_jni<JHybridImageSpec>(jni::make_global(__result));
  }
  std::shared_ptr<margelo::nitro::image::HybridImageSpec> JHybridImageFactorySpec::bounceBack(const std::shared_ptr<margelo::nitro::image::HybridImageSpec>& image) {
    static const auto method = javaClassStatic()->getMethod<jni::local_ref<JHybridImageSpec::javaobject>(jni::alias_ref<JHybridImageSpec::javaobject> /* image */)>("bounceBack");
    auto __result = method(_javaPart, std::dynamic_pointer_cast<JHybridImageSpec>(image)->getJavaPart());
    return JNISharedPtr::make_shared_from_jni<JHybridImageSpec>(jni::make_global(__result));
  }

} // namespace margelo::nitro::image
