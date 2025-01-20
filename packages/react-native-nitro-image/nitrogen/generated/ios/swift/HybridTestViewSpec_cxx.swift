///
/// HybridTestViewSpec_cxx.swift
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges HybridTestViewSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HybridObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public class HybridTestViewSpec_cxx {
  /**
   * The Swift <> C++ bridge's namespace (`margelo::nitro::image::bridge::swift`)
   * from `NitroImage-Swift-Cxx-Bridge.hpp`.
   * This contains specialized C++ templates, and C++ helper functions that can be accessed from Swift.
   */
  public typealias bridge = margelo.nitro.image.bridge.swift

  /**
   * Holds an instance of the `HybridTestViewSpec` Swift protocol.
   */
  private var __implementation: any HybridTestViewSpec

  /**
   * Holds a weak pointer to the C++ class that wraps the Swift class.
   */
  private var __cxxPart: bridge.std__weak_ptr_margelo__nitro__image__HybridTestViewSpec_

  /**
   * Create a new `HybridTestViewSpec_cxx` that wraps the given `HybridTestViewSpec`.
   * All properties and methods bridge to C++ types.
   */
  public init(_ implementation: any HybridTestViewSpec) {
    self.__implementation = implementation
    self.__cxxPart = .init()
    /* no base class */
  }

  /**
   * Get the actual `HybridTestViewSpec` instance this class wraps.
   */
  @inline(__always)
  public func getHybridTestViewSpec() -> any HybridTestViewSpec {
    return __implementation
  }

  /**
   * Casts this instance to a retained unsafe raw pointer.
   * This acquires one additional strong reference on the object!
   */
  public func toUnsafe() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(self).toOpaque()
  }

  /**
   * Casts an unsafe pointer to a `HybridTestViewSpec_cxx`.
   * The pointer has to be a retained opaque `Unmanaged<HybridTestViewSpec_cxx>`.
   * This removes one strong reference from the object!
   */
  public class func fromUnsafe(_ pointer: UnsafeMutableRawPointer) -> HybridTestViewSpec_cxx {
    return Unmanaged<HybridTestViewSpec_cxx>.fromOpaque(pointer).takeRetainedValue()
  }

  /**
   * Gets (or creates) the C++ part of this Hybrid Object.
   * The C++ part is a `std::shared_ptr<margelo::nitro::image::HybridTestViewSpec>`.
   */
  public func getCxxPart() -> bridge.std__shared_ptr_margelo__nitro__image__HybridTestViewSpec_ {
    let cachedCxxPart = self.__cxxPart.lock()
    if cachedCxxPart.__convertToBool() {
      return cachedCxxPart
    } else {
      let newCxxPart = bridge.create_std__shared_ptr_margelo__nitro__image__HybridTestViewSpec_(self.toUnsafe())
      __cxxPart = bridge.weakify_std__shared_ptr_margelo__nitro__image__HybridTestViewSpec_(newCxxPart)
      return newCxxPart
    }
  }

  

  /**
   * Get the memory size of the Swift class (plus size of any other allocations)
   * so the JS VM can properly track it and garbage-collect the JS object if needed.
   */
  @inline(__always)
  public var memorySize: Int {
    return MemoryHelper.getSizeOf(self.__implementation) + self.__implementation.memorySize
  }

  // Properties
  public var someProp: Bool {
    @inline(__always)
    get {
      return self.__implementation.someProp
    }
    @inline(__always)
    set {
      self.__implementation.someProp = newValue
    }
  }
  
  public var someCallback: bridge.Func_void_double {
    @inline(__always)
    get {
      return { () -> bridge.Func_void_double in
        let __closureWrapper = Func_void_double(self.__implementation.someCallback)
        return bridge.create_Func_void_double(__closureWrapper.toUnsafe())
      }()
    }
    @inline(__always)
    set {
      self.__implementation.someCallback = { () -> (Double) -> Void in
        let __wrappedFunction = bridge.wrap_Func_void_double(newValue)
        return { (__someParam: Double) -> Void in
          __wrappedFunction.call(__someParam)
        }
      }()
    }
  }

  // Methods
  @inline(__always)
  public func someFunc(someParam: Double) -> bridge.Result_bool_ {
    do {
      let __result = try self.__implementation.someFunc(someParam: someParam)
      let __resultCpp = __result
      return bridge.create_Result_bool_(__resultCpp)
    } catch (let __error) {
      let __exceptionPtr = __error.toCpp()
      return bridge.create_Result_bool_(__exceptionPtr)
    }
  }
  
  public final func getView() -> UnsafeMutableRawPointer {
    return Unmanaged.passRetained(__implementation.view).toOpaque()
  }
  
  public final func beforeUpdate() {
    __implementation.beforeUpdate()
  }
  
  public final func afterUpdate() {
    __implementation.afterUpdate()
  }
}
