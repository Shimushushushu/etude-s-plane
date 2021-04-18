#include "color.h"

#include <algorithm>
#include <cstddef>

namespace etude {

constexpr double oneD6 = 0.166667;

colorf_t::colorf_t(colorf_t::type_t t) : type{t} {}

colorf_t::colorf_t(std::initializer_list<double> l, colorf_t::type_t t)
    : type(t) {
  std::copy(l.begin(), l.end(), this->begin());
}

colorf_t::~colorf_t() {}

color8_t colorf_t::To8_t() const {
  color8_t ret{0, 0, 0};

  // convert them from [0.0, 1.0] to [0, 255)
  for (std::size_t i = 0; i < ret.max_size(); ++i) {
    ret[i] = static_cast<color8_t::value_type>(at(i) * 255.99);
  }

  return ret;
}

colorf_t Hsl2Rgb(const colorf_t &c) {
  colorf_t ret{0.0, 0.0, 0.0};

  // find (R, G, B) corresponding to (H, 1.0, 0.5)
  switch (static_cast<int>(c[0] / oneD6)) {
   case 0:
    ret[0] = 1.0;
    ret[1] = (c[0] - 0.0 * oneD6) / oneD6; break;
   case 1:
    ret[1] = 1.0;
    ret[0] = (2.0 * oneD6 - c[0]) / oneD6; break;
   case 2:
    ret[1] = 1.0;
    ret[2] = (c[0] - 2.0 * oneD6) / oneD6; break;
   case 3:
    ret[2] = 1.0;
    ret[1] = (4.0 * oneD6 - c[0]) / oneD6; break;
   case 4:
    ret[2] = 1.0;
    ret[0] = (c[0] - 4.0 * oneD6) / oneD6; break;
   case 5:
    ret[0] = 1.0;
    ret[2] = (6.0 * oneD6 - c[0]) / oneD6; break;
   default:
    break;
  }

  // find (R, G, B) corresponding to (H, 1.0, L)
  if (c[2] <= 0.5) {
    for (auto& itr : ret) {
      itr = (1.0 - 2.0 * c[2]) * 0.0 + (2.0 * c[2] - 0.0) * itr;
    }
  } else {
    for (auto& itr : ret) {
      itr = (2.0 * c[2] - 1.0) * 1.0 + (2.0 - 2.0 * c[2]) * itr;
    }
  }

  // find (R, G, B) corresponding to (H, S, L)
  for (auto& itr : ret) {
    itr = c[1] * itr + (1.0 - c[1]) * c[2];
  }

  return ret;
}

} // namespace etude

std::ostream& operator<<(std::ostream& os, const etude::color8_t& c) {
  // static_cast<int> must be used in case that os treats them as chars
  os << "(" << static_cast<int>(c[0]) << ", "
            << static_cast<int>(c[1]) << ", "
            << static_cast<int>(c[2]) << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const etude::colorf_t& c) {
  os << "(" << c[0] << ", " << c[1] << ", " << c[2] << ")";
  return os;
}