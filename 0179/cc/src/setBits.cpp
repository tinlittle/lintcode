#include "setBits.h"
// two step process
// 1. need to construct a bitmask patter of 1..0.0..1, where the middel zero range
//  start from bit i and ends with bit j
// 2. need to shift m to start at bit i, like 0.m.0, there is i number of trailing zeros


unsigned char bitmath::zeroFilledMask(int i, int j) {
  unsigned char mask = 1;
  if ((j - i + 1) >= sizeof(unsigned char) * 8)
    return 0;
  mask = mask << (j - i + 1);
  mask -= 1;
  mask = mask << i;
  mask = ~mask;
  return mask;
}

unsigned char bitmath::setBits(unsigned char n, unsigned char m, int i, int j) {
  if (i < 0 || j <  0 || i > j)
    return n; // invalid range, just return input unchanged
  unsigned char zeroMask = zeroFilledMask(i, j);
  n = n & zeroMask;
  m = m << i;
  n = n | m;
  return n;
}