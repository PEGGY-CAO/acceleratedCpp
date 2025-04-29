#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <functional>
#include <catch2/catch.hpp>
#include <optional>

namespace Catch {
  template <typename T> requires std::integral<T> or std::floating_point<T>
  struct StringMaker<std::optional<T>> {
    static std::string convert(std::optional<T> const& p) {
      if (p.has_value()) {
        return std::to_string(p.value());
      }
      else {
        return "nullopt";
      }
    }
  };

  template <typename T> requires std::convertible_to<T, std::string>
  struct StringMaker<std::optional<T>> {
    static std::string convert(std::optional<T> const& p) {
      if (p.has_value()) {
        return p.value();
      }
      else {
        return "nullopt";
      }
    }
  };

  template <> struct StringMaker<std::nullopt_t> {
    static std::string convert(std::nullopt_t p) {
      return "nullopt";
    }
  };

};

class Utility {
 public:
  static void CheckTimeout(std::function<void()> func, int timeout_in_milliseconds);
};

#endif // UTILITY_HPP_
