///
/// HybridSwiftKotlinTestObjectSpec.swift
/// Tue Aug 13 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A Swift protocol representing the SwiftKotlinTestObject HybridObject.
 * Implement this protocol to create Swift-based instances of SwiftKotlinTestObject.
 *
 * When implementing this protocol, make sure to initialize `hybridContext` - example:
 * ```
 * public class HybridSwiftKotlinTestObject : HybridSwiftKotlinTestObjectSpec {
 *   // Initialize HybridContext
 *   var hybridContext = margelo.nitro.HybridContext()
 *
 *   // Return size of the instance to inform JS GC about memory pressure
 *   var memorySize: Int {
 *     return getSizeOf(self)
 *   }
 *
 *   // ...
 * }
 * ```
 */
public protocol HybridSwiftKotlinTestObjectSpec: HybridObjectSpec {
  // Properties
  var numberValue: Double { get set }
  var boolValue: Bool { get set }
  var stringValue: String { get set }
  var bigintValue: Int64 { get set }
  var stringOrUndefined: String? { get set }
  var stringOrNull: String? { get set }
  var optionalString: String? { get set }

  // Methods
  func simpleFunc() throws -> Void
  func addNumbers(a: Double, b: Double) throws -> Double
  func addStrings(a: String, b: String) throws -> String
  func multipleArguments(num: Double, str: String, boo: Bool) throws -> Void
  func getNumbers() throws -> [Double]
  func getStrings() throws -> [String]
  func callCallback(callback: (@escaping () -> Void)) throws -> Void
}

public extension HybridSwiftKotlinTestObjectSpec {
  /**
   * Create a new instance of HybridSwiftKotlinTestObjectSpecCxx for the given HybridSwiftKotlinTestObjectSpec.
   *
   * Instances of HybridSwiftKotlinTestObjectSpecCxx can be accessed from C++, and contain
   * additional required bridging code for C++ <> Swift interop.
   */
  func createCxxBridge() -> HybridSwiftKotlinTestObjectSpecCxx {
    return HybridSwiftKotlinTestObjectSpecCxx(self)
  }
}