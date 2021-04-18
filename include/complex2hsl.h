#ifndef __ETUDE_INCLUDE_COMPLEX2HSL_H
#define __ETUDE_INCLUDE_COMPLEX2HSL_H

#include <complex>

#include "color.h"

namespace etude {

using real_t = long double;
using complex_t = std::complex<real_t>;

colorf_t Complex2Hsl(complex_t z);

} // namespace etude

#endif // __ETUDE_INCLUDE_COMPLEX2HSL_H