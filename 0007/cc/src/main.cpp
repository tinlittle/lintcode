#include "BTreeSerialization.cpp"

#include <iostream>

int main() {
  TreeNode n4(15), n5(7),n2(9);
  TreeNode n3(20, &n4, &n5);
  TreeNode n1(3, &n2, &n3);

  TreeNode m4(4);
  TreeNode m3(3, &m4, nullptr);
  TreeNode m2(2, &m3, nullptr);
  TreeNode m1(1, &m2, nullptr);
 


  Solution s;
  std::string data = s.serialize(&m1);
  std::cout << "data : " << data << std::endl;

  TreeNode *root = s.deserialize(data);

  std::string data2 = s.serialize(root);
  assert(data == data2);
  std::cout << "data2: " << data2 << std::endl;
  return 0;
}