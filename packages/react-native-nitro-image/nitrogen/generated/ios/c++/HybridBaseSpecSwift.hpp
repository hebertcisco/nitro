///
/// HybridBaseSpecSwift.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#include "HybridBaseSpec.hpp"

// Forward declaration of `HybridBaseSpec_cxx` to properly resolve imports.
namespace NitroImage { class HybridBaseSpec_cxx; }





#include "NitroImage-Swift-Cxx-Umbrella.hpp"

namespace margelo::nitro::image {

  /**
   * The C++ part of HybridBaseSpec_cxx.swift.
   *
   * HybridBaseSpecSwift (C++) accesses HybridBaseSpec_cxx (Swift), and might
   * contain some additional bridging code for C++ <> Swift interop.
   *
   * Since this obviously introduces an overhead, I hope at some point in
   * the future, HybridBaseSpec_cxx can directly inherit from the C++ class HybridBaseSpec
   * to simplify the whole structure and memory management.
   */
  class HybridBaseSpecSwift: public virtual HybridBaseSpec {
  public:
    // Constructor from a Swift instance
    explicit HybridBaseSpecSwift(const NitroImage::HybridBaseSpec_cxx& swiftPart):
      HybridObject(HybridBaseSpec::TAG),
      _swiftPart(swiftPart) { }

  public:
    // Get the Swift part
    inline NitroImage::HybridBaseSpec_cxx& getSwiftPart() noexcept {
      return _swiftPart;
    }

  public:
    // Get memory pressure
    inline size_t getExternalMemorySize() noexcept override {
      return _swiftPart.getMemorySize();
    }

  public:
    // Properties
    inline double getBaseValue() noexcept override {
      return _swiftPart.getBaseValue();
    }

  public:
    // Methods
    

  private:
    NitroImage::HybridBaseSpec_cxx _swiftPart;
  };

} // namespace margelo::nitro::image
