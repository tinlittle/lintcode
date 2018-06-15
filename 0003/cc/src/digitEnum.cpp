
#include <cstddef>
#include "digitEnum.h"


// private
namespace digitEnum {

};

std::size_t digitEnum::totalSpecifiedDigitOccurancesUpto(int N, int k) {
  // abcde
  // for position 2, occupied by digit c, need to separate the following 3 items:
  // 1. higher order number: ab or ab000, looks like ab is better with an accumulating multiplier
  // 2. current number: c (or c00)
  // 3. lower order number: de, only useful when c == k
  // for #1, abcde / 1000 = ab
  // for #2, abcde / 100 = abc, abc % 10 = c
  // for #3, abcde % 100 = de
  // with #1, total of 100 * ab occurances of k below ab000
  std::size_t total = 0;

  int higher = 0, current = 0, lower = 0;
  std::size_t order = 0;
  int head_divisor = 10; // used to get higher order number, increase by muliple of 10
  int curtail_divisor = 1; // used to remove digits after current digit, increase by muliple of 10
  int tail_divisor = 1; // used to get the lower order number as a remaider, increase by multiple of 10
  std::size_t block_size = 1; // number of permutations of specified digit at current order, increase by multiple of 10 

  if (N == 0) {
    if (k == 0)
      total = 1;
    return total;
  }

  do {
    higher = N / head_divisor;
    current = N / curtail_divisor;
    current = current % 10;
    lower = N % tail_divisor;

    if (higher == 0 && current == 0)
      break;

    if (current < k)
      total += higher * block_size;
    else if (current > k) {
      if (higher != 0 || k != 0)
        total += (higher + 1) * block_size;
    }
    else
      if (higher != 0 || k != 0) { // current is msd
        total += higher * block_size + lower + 1;
      }
    if (higher == 0 && order == 0 && k == 0)  // single digit case
      total = 1;

    order++;
    head_divisor *= 10;
    curtail_divisor *= 10;
    tail_divisor *= 10;
    block_size *= 10;
  } while (true);

  return total;
}


