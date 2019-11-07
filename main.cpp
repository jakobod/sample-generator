/**
 * @file main.cpp
 * @author Jakob Otto (jakob.otto@haw-hamburg.de)
 * @date 2019-11-07
 */

#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

// Number of sign bits in our Q-format.
constexpr uint8_t sign_bit = 1;
// Number of integer bits in our Q-format.
constexpr uint8_t integer_bits = 0;
// Number of fractional bits in our Q-format.
constexpr uint8_t fractional_bits = 11;
// Maximum amplitude value.
constexpr auto max_value = 1 << fractional_bits;
// Half amplitude value
constexpr auto mid = max_value >> 2;

// type alias for fixed_point type.
using fixed_point = uint16_t;
// Binary printable type alias.
using binary_string = std::bitset<sign_bit + integer_bits + fractional_bits>;

/// Converts a doubleing_point number to a fixed_point type.
fixed_point to_fixed(double input) {
  return static_cast<fixed_point>(round(input * (1 << fractional_bits)));
}

/// Converts a fixed_point number to doubleing_point type.
double to_double(fixed_point input) {
  return (static_cast<double>(input)
          / static_cast<double>(1u << fractional_bits));
}

/// Returns a bitset containing 'x' which can be printed in binary format.
template <class T>
binary_string to_binary(T x) {
  return binary_string(x);
}

/// Prints any std::vector with newlines and fancy formatting.
template <class Type>
void print_vector(const std::vector<Type>& values, const int line_width = 15) {
  int count = 0;
  for (const auto val : values) {
    std::cout << std::setw(5) << val << ", ";
    // add newline every `line_width` prints.
    if (++count >= line_width) {
      count = 0;
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

int main() {
  std::vector<fixed_point> sinusSamples;
  std::vector<fixed_point> sawToothSamples;

  // sinus calculation
  const auto sinStep = (2 * M_PI) / 360;
  auto rad = 0.0;
  for (int i = 0; i < 360; ++i) {
    auto sinSample = std::floor((std::sin(rad) * mid));
    auto scaled_sin_sample = sinSample / mid;
    sinusSamples.push_back(to_fixed(scaled_sin_sample));
    rad += sinStep;
  }

  // sawtooth calculation
  const double sawStep = max_value / 360;
  double sawSample = 0.0;
  for (int i = 0; i < 360; ++i) {
    sawToothSamples.push_back(to_fixed(sawSample));
    sawSample += sawStep / max_value;
  }

  // Print data
  std::cout << "Sinus samples:" << std::endl;
  print_vector(sinusSamples);
  std::cout << "Sawtooth samples:" << std::endl;
  print_vector(sawToothSamples);
}
