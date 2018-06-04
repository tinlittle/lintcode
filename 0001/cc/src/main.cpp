#include <iostream>

#include "bitmath.h"

int main() {
  unsigned char x, y, z;
  x = bitmath::plusv2(1, 255);
  y = bitmath::plusv2(255, 1);
  z = bitmath::plusv2(126, 238);
  if (x == 0 && y == 0 && z == 108)
    std::cout << "success" << std::endl;
  return 0;
}