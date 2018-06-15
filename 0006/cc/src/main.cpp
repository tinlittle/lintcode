#include "merge.cpp"

#include <iostream>

auto print = [] (int i) {
  std::cout << " " << i << std::endl;
};

int main () {
  Solution s;

  std::vector<int> a {1,2,2,4,5,6};
  std::vector<int> b {2,3,4,4,7,8};

  std::vector<int> c = s.mergeSortedArray(a, b);

  std::vector<int> x {1};
  std::vector<int> y {1};

  std::vector<int> z = s.mergeSortedArray(x, y);

  for_each(z.begin(), z.end(), print);

  return 0;
}