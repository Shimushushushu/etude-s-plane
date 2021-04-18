#include <cstddef>
#include <fstream>

#include "color.h"
#include "complex2hsl.h"

constexpr std::size_t kWidth  = 1024;
constexpr std::size_t kHeight = 1024;

constexpr etude::real_t k_ = 100;

etude::complex_t f(etude::complex_t z) {
  return std::log(z);
}

etude::complex_t Map2Complex(std::size_t w, std::size_t h) {
  etude::complex_t ret(w, h);
  ret -= etude::complex_t(static_cast<etude::real_t>(kWidth)  / 2.0,
                          static_cast<etude::real_t>(kHeight) / 2.0);
  ret /= k_;
  return ret;
}

int main(int argc, char** argv) {
  using std::endl;
  std::ios::sync_with_stdio(false);

  std::ofstream fout("out.ppm");
  fout << "P3" << endl
       << kWidth << " " << kHeight << endl
       << "255" << endl;

  etude::complex_t bufferZ;
  etude::color8_t  bufferC;

  for (std::size_t h = kHeight; h > 0; --h) {
    for (std::size_t w = 0; w < kWidth; ++w) {
      bufferZ = f(Map2Complex(w, h));
      bufferC = etude::Hsl2Rgb(etude::Complex2Hsl(bufferZ)).To8_t();
      fout << static_cast<int>(bufferC[0]) << " "
           << static_cast<int>(bufferC[1]) << " "
           << static_cast<int>(bufferC[2]) << endl;
    }
  }

  fout.close();
  return 0;
}