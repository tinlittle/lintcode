#include "setBits.h"

#include <iostream>

int main() {
  unsigned char n1 = 0xFF;
  unsigned char n2 = 0x80;
  unsigned char m1 = 5, m2 = 7;
  int i1 = 0, j1 = 2, i2 = 3, j2 = 5;
  unsigned char r1 = 0xFD; // 1111,1101
  unsigned char r2 = 0xB8; // 1011,1000

  if (r1 == bitmath::setBits(n1, m1, i1, j1) && r2 == bitmath::setBits(n2, m2, i2, j2))
    std::cout << "success" << std::endl;
    
  return 0;
}