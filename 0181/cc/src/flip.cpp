#include "flip.h"

unsigned char bitmath::numSetBitsv1(unsigned char a) {
  const unsigned char msbMask = 128; // 0x80, 0-1000,1000
  unsigned char numOfSetBits = 0;
  while (a) {
    if (msbMask & a)
      numOfSetBits++;
    a = a << 1;
  }
  return numOfSetBits;
}

unsigned char bitmath::numSetBitsv2(unsigned char a) {
  unsigned char numOfSetBits = 0;
  while (a) {
    numOfSetBits++;
    a &= (a-1);
  }

  return numOfSetBits;
}

unsigned char bitmath::numSetBitsv3(unsigned char x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;

}

bool bitmath::isPowerOfTwo(unsigned char a) {
  return !(a & (a-1));
}

unsigned char bitmath::gap(unsigned char a, unsigned char b) {
  return bitmath::numSetBitsv3(a ^ b);
}