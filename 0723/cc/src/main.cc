#include "bitRotate.cc"
#include <cassert>

int main() {
  Solution s;
  int n1 = 0x80000000;
  int n2 = 0x40000000;

  int n3 = 0x8000000;
  int n4 = 0x4000000;

  int m1 = s.leftRotate(n1, 3);
  int m2 = s.leftRotate(n2, 4);
  assert (m1 == m2);

  int m3 = s.leftRotate(n3, 4);
  assert(n1 == m3);
  assert(n2 == s.leftRotate(n4, 4));
}