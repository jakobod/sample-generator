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

// -- Constants ----------------------------------------------------------------

// Number of samples to be calculated.
constexpr uint16_t sample_count = 360;
// Maximum amplitude value.
constexpr uint16_t max_value = 0b111111111111;
// Half amplitude value
constexpr uint16_t mid = max_value >> 1;

// -- Type aliases -------------------------------------------------------------

// Binary printable type alias.
using binary_type = std::bitset<8 * sizeof(uint16_t)>;

// -- Helper functions ---------------------------------------------------------

/// Returns a bitset containing 'x' which can be printed in binary format.
template <class T>
binary_type to_binary(T x) {
  return binary_type(x);
}

/// Prints any std::vector with newlines and fancy formatting.
template <class Type>
void print_vector(const std::vector<Type>& values, const int line_width = 15) {
  int count = 0;
  for (const auto val : values) {
    std::cout << std::setw(6) << val << ", ";
    // add newline every `line_width` prints.
    if (++count >= line_width) {
      count = 0;
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int16_t> sinusSamples;
  std::vector<int16_t> sawToothSamples;

  // sinus calculation
  auto rad = (2 * M_PI) / 360;
  for (int i = 0; i < sample_count; ++i) {
    double sinSample = (std::sin(i * rad));
    auto x = static_cast<uint64_t>((sinSample * (32768)));
    // catch edgecase
    if (x == 32768)
      x -= 1;
    sinusSamples.push_back(x);
  }

  // sawtooth calculation
  const double saw_step = max_value / sample_count;
  for (int i = 0; i < sample_count; ++i) {
    auto sample = saw_step * i;
    double scaled_saw_sample = (sample - mid) / max_value;
    auto x = static_cast<uint64_t>((scaled_saw_sample * (32768)));
    sawToothSamples.push_back(x);
  }

  // Print data
  std::cout << "Sinus samples:" << std::endl;
  print_vector(sinusSamples);
  std::cout << "Sawtooth samples:" << std::endl;
  print_vector(sawToothSamples);
}
