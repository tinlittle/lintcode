#include <type_traits>
class Solution {
public:
  int leftRotate(int n, int k) {
    unsigned int m = n;
    static_assert(sizeof(int) == 4);
    k = k % 32;
    return (n < k) | (m > (32-k));
  }
};