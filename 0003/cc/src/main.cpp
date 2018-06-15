#include "digitCount.h"
#include "digitEnum.h"

#include <iostream>
#include <array>

int main() {

  std::array<int, 10> N = {{5, 5, 55,55, 55, 55, 555, 1000, 555555, 12373}};
  std::array<int, N.size()> k =   {5, 0, 0, 4, 5,   6,  5, 1, 5, 2};
  std::array<std::size_t, N.size()> result1;
  std::array<std::size_t, N.size()> result2;

  for (std::size_t i = 0; i < N.size(); i++)
    std::cout << N[i] << " and " << k[i] << " is" << 
      " r1: " << (result1[i] = digitMath::numOfAllSpecifiedDigitUpto(N[i], k[i])) <<
      " r2: " << (result2[i] = digitEnum::totalSpecifiedDigitOccurancesUpto(N[i], k[i])) << std::endl;

  return 0;
}