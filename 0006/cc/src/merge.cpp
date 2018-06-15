#include <vector>


class Solution {
public:
  /**
   * @param A: sorted integer array A
   * @param B: sorted integer array B
   * @return: A new sorted integer array
   * 
   * 
   */
  std::vector<int> mergeSortedArray(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> C;
    std::vector<int>::const_iterator a = A.begin();
    std::vector<int>::const_iterator b = B.begin();
    std::vector<int>::iterator c;
      auto copy_list = [&C = C] (std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) mutable {
      while (first != last) {
        C.push_back(*first);
        ++first;
      }
    };
    while (a != A.end() && b != B.end()) {
      if (*a <= *b) {
        C.push_back(*a);
        a++;
      }
      else {
        C.push_back(*b);
        b++;
      }
    }
    c = C.end();
    if (a == A.end())
      copy_list(b, B.end());
    else
      copy_list(a, A.end());

    return C;
  }
};