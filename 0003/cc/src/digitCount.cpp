#include "digitCount.h"

namespace digitMath {
std::size_t tensPow(std::size_t n) {
  std::size_t pow = 1;
  for (std::size_t i = 0; i < n; i++)
    pow *= 10;
  return pow;
}

std::size_t numOfSpecifiedDigitAtMSDUpto(int M, int k, std::size_t order) {
  // M is or order "order", like 55 has order of 1, 555 has order of 2
  // assuming k == 5, we are passing in (5, 5, 0), (55, 5, 1), (655, 5, 2), and (555, 5, 2)
  // for (5, 5, 0), we should return 1
  //  blockSize = 1, divisor = 1, msdDigit = 5, rem = 0

  // for (55, 5, 1), we should return 6
  // blockSize = 10, divisor = 10, msDigit = 5, rem = 5

  // for (655, 5, 2), we should return 100
  // blockSize = 100, divisor = 100, msDigit = 6, rem = 55

  // for (555, 5, 2), we should return 56
  // blockSize = 100, divisor = 100, msDigit = 5, rem = 55

  // edge cases when k = 0
  if (k == 0) {
    if (order == 0)
      return 1; // leading zero only valid when the order is 0
    else
      return 0;
  }
  // order is the current (msd) position to be evaluated
  std::size_t numDigitsPerBlock = digitMath::tensPow(order);
  // the divisor needed to separate msd, divisor not needed for order 0
  std::size_t divisor = digitMath::tensPow(order);

  // the single msd digit, if order is zero, no divisor applicable
  int msdDigit;
  if (order == 0)
    msdDigit = M;
  else
    msdDigit = M / divisor;

  // the reminder after taking off of MSD, act as a counter, if order is zero, rem has a nominal value of zero
  int rem;
  if (order == 0)
    rem = 0;
  else
    rem = M % divisor;

  if (msdDigit < k)
    return 0;
  else if (msdDigit > k) 
    return numDigitsPerBlock;
  else // msdDigit == k
    return rem + 1;
}
};

std::size_t numOfBulkDigitsPerBlockAt(std::size_t position) {
  return digitMath::tensPow(position);
}

// The divisor to separate MSD at the position specified
// like for position 0, divisor is 10, 11 % 10 = 1, 121 % 10 = 1, etc
std::size_t getDivisor(std::size_t position) {
  return digitMath::tensPow(position + 1);
}

std::size_t getHighestOrder(int N) {
  // all integars at least has a order of 0
  std::size_t order = 0;
  N /= 10;
  while (N != 0) {
    order++;
    N /= 10;
  }
  return order;
}

std::size_t digitMath::numOfAllSpecifiedDigitUpto(int N, int k) {
  std::size_t totalNumberOfSpecifiedDigits = 0;

  std::size_t highestPosition = getHighestOrder(N);
  for (std::size_t position = 0; position <= highestPosition; position++) {
    // the remainder after taking off higher order bits and left current position
    // at msd
    std::size_t rem; 
    if (position == highestPosition)
      rem = N;
    else {
      // first cacualte block by block
      // the divisor to separate current position as msd from higher order positions
      std::size_t divisor = getDivisor(position);
      // unit of increase for current position
      std::size_t numDigitsPerBlock = numOfBulkDigitsPerBlockAt(position);
      std::size_t numOfWholeBlocks = N / divisor;
      totalNumberOfSpecifiedDigits += numOfWholeBlocks * numDigitsPerBlock;

      // now with the rest of N rem with current position at MSD
      rem = N % divisor;
    }
    totalNumberOfSpecifiedDigits += numOfSpecifiedDigitAtMSDUpto(rem, k, position);
  }

  return totalNumberOfSpecifiedDigits;
}