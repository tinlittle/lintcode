#include "bitmath.h"

unsigned char bitmath::plusv1(unsigned char a, unsigned char b) {
  unsigned char result = a;
  unsigned char ssum, carry;
  result = ssum = a ^ b;
  carry = (a & b) << 1;
  while (carry) {
    result = ssum ^ carry;
    carry = (ssum & carry) << 1;
    ssum = result;
  }
  return result;
}

unsigned char bitmath::plusv2(unsigned char a, unsigned char b) {
  unsigned char result;
  do {
    result = a ^ b;
    b = (a & b) << 1;
    a = result;
  } while (b);
  return result;
}