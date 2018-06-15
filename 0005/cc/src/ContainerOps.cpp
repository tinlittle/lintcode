#include "ContainerOps.h"

#include <functional>

int ContainerOps::kthLargestElement(int k, std::array<int, 10> &nums){
  std::array<int, 10>::iterator i = nums.begin();
  std::array<int, 10>::iterator ki = nums.begin(); std::advance(ki, (k < nums.size() ? k - 1 : nums.size() - 1));
  std::sort(nums.begin(), 
      ki/*,
      std::greater<int>() */
    );

  ki = nums.begin() + (k < nums.size() ? k - 1 : nums.size() - 1);

  std::array<int, 10>::iterator rest = ki + 1;
  std::iter_swap(nums.begin(), rest);
  while (rest != nums.end()) {
    if (*rest > *ki) {
      std::swap(rest, ki);
      std::sort(nums.begin(), ki, std::greater<int>());
    }
    rest++;
  }

  return *ki;
}