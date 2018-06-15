#include "flip.h"

#include <iostream>

int main() {
  unsigned char x = bitmath::gap(128, 127);
  unsigned char y = bitmath::gap(0xFF, 0x7F);
  unsigned char z = bitmath::gap(0, 1);

  bool a = bitmath::isPowerOfTwo(2);
  bool b = bitmath::isPowerOfTwo(128);
  bool c = bitmath::isPowerOfTwo(55);
  if (x == 8 && y == 1 && z == 1 && a && b && !c)
    std::cout << "success" << std::endl;
  
  return 0;
}