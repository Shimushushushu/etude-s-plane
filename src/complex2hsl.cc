#include "complex2hsl.h"

#include <cmath>

namespace etude {

real_t l_(real_t r) {
  return (2.0 / 3.14159) * std::atan(r);
}

colorf_t Complex2Hsl(complex_t z) {
  colorf_t ret{{0.0, 0.0, 0.0}, colorf_t::kHsl};

  // find (H, S, L) corresponding to z = r * e ^ (i * theta)
  ret[0] = std::arg(z) / (2.0 * 3.14159);
  if (ret[0] < 0) { ret[0] += 1.0; }
  ret[1] = 1.0;
  ret[2] = l_(std::abs(z));

  return ret;
}

} // namespace etude