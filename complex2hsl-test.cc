#include "complex2hsl.h"

#include <iostream>

int main(int argc, char** argv) {
  etude::complex_t z(1, 0);
  std::cout << etude::Complex2Hsl(z) << std::endl;

  return 0;
}