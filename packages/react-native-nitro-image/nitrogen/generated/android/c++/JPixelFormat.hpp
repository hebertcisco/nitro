///
/// JPixelFormat.hpp
/// Mon Jul 29 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "PixelFormat.hpp"

namespace margelo::nitro::image {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ enum "PixelFormat" and the the Kotlin enum "PixelFormat".
   */
  struct JPixelFormat: public jni::JavaClass<JPixelFormat> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/PixelFormat;";

  public:
    /**
     * Convert this Java/Kotlin-based enum to the C++ enum PixelFormat.
     */
    PixelFormat toPixelFormat() {
      static const auto clazz = javaClassStatic();
      static const auto fieldOrdinal = clazz->getField<int>("ordinal");
      int ordinal = this->getFieldValue(fieldOrdinal);
      return static_cast<PixelFormat>(ordinal);
    }

  public:
    /**
     * Create a Java/Kotlin-based enum with the given C++ enum's value.
     */
    static jni::local_ref<JPixelFormat::javaobject> create(PixelFormat value) {
      static const auto clazz = javaClassStatic();
      static const auto fieldRGB = clazz->getStaticField<JPixelFormat>("RGB");
      static const auto fieldYUV_8BIT = clazz->getStaticField<JPixelFormat>("YUV_8BIT");
      static const auto fieldYUV_10BIT = clazz->getStaticField<JPixelFormat>("YUV_10BIT");
      
      switch (value) {
        case PixelFormat::RGB:
          return clazz->getStaticFieldValue(fieldRGB);
        case PixelFormat::YUV_8BIT:
          return clazz->getStaticFieldValue(fieldYUV_8BIT);
        case PixelFormat::YUV_10BIT:
          return clazz->getStaticFieldValue(fieldYUV_10BIT);
        default:
          std::string stringValue = std::to_string(static_cast<int>(value));
          throw std::runtime_error("Invalid enum value (" + stringValue + "!");
      }
    }
  };

} // namespace margelo::nitro::image