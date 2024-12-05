//
//  RuntimeError.hpp
//  NitroModules
//
//  Created by Marc Rousavy on 19.11.24.
//

#pragma once

#include "TypeInfo.hpp"
#include <exception>
#include <string>

namespace margelo::nitro {

static inline std::exception_ptr make_exception(const std::string& message) {
  return std::make_exception_ptr(std::runtime_error(message));
}

static inline std::string get_exception_message(const std::exception_ptr& exception) {
  if (exception == nullptr) [[unlikely]] {
    throw std::runtime_error("Cannot get error message of an empty exception_ptr!");
  }

  try {
    std::rethrow_exception(exception);
  } catch (const std::exception& error) {
    return error.what();
  } catch (...) {
    std::string errorName = TypeInfo::getCurrentExceptionName();
    return "Unknown " + errorName + " exception";
  }
}

} // namespace margelo::nitro