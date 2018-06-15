#include "uglyQueue.h"

#include <iostream>
#include <array>

int main () {
  UglyNumber* theNumber = new UglyNumber();

  long long u = theNumber->getNthUglyNumber2(9);
  long long v = theNumber->getNthUglyNumber(1000);
  return 0;
}