#ifndef __ETUDE_INCLUDE_COLOR_H
#define __ETUDE_INCLUDE_COLOR_H

#include <array>
#include <cstdint>
#include <initializer_list>
#include <ostream>

namespace etude {

using color8_t = std::array<std::uint8_t, 3>;
class colorf_t : public std::array<double, 3> {
 public:
  enum type_t {kRgb, kHsl, kHsv};

  colorf_t(type_t t = kRgb);
  colorf_t(std::initializer_list<double> l, type_t t = kRgb);
  ~colorf_t();

  color8_t To8_t() const;

  type_t type;
};

colorf_t Hsl2Rgb(const colorf_t& c);

// deprecated: use the member function To8_t() instead
color8_t f_t28_t(const colorf_t& c) = delete;

} // namespace etude

std::ostream& operator<<(std::ostream& os, const etude::color8_t& c);
std::ostream& operator<<(std::ostream& os, const etude::colorf_t& c);

#endif // __ETUDE_INCLUDE_COLOR_H