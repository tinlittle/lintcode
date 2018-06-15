#include "BTreeRange.cc"

#include <iostream>

int main() {

  Solution s;
  std::string str {"20,8,22,4,12"};

  TreeNode *root = s.deserialize(str);

  std::vector<int> arr;

  s.traverseBounded(root, arr, 8, 20);

  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}