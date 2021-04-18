#include "color.h"

#include <iostream>
#include <cstddef>
#include <string>

int main(int argc, char** argv) {
  using std::cin;
  using std::cout;
  using std::endl;

  etude::colorf_t c(etude::colorf_t::kRgb);

  for (std::size_t i = 1; i < 4 && i < argc; ++i) {
    c[i - 1] = std::stof(argv[i]);
  }
  // for (auto& itr : c) {
  //   cin >> itr;
  // }
  c[0] /= 360.0;
  c[1] /= 100.0;
  c[2] /= 100.0;
  // cout << c << endl;

  // auto res = etude::f_t28_t(etude::Hsl2Rgb(c));
  auto res = etude::Hsl2Rgb(c).To8_t();
  cout << res << endl;

  return 0;
}