#include <vector>

class Solution {
public:
  /**
   * @param L: an integer
   * @param R: an integer
   * @return: the count of numbers in the range [L, R] having a prime number of set bits in their binary representation
   */
  Solution();
  int countPrimeSetBits(int L, int R) {
    
    return 0;
  }
  bool isPrime[22];
  std::vector<std::vector<unsigned int>> popTable;
};

Solution::Solution() : isPrime {
      false,  // 0
      false,  // 1
      true,   // 2
      true,   // 3
      false,
      true,   // 5
      false,
      true,   // 7
      false,
      false,
      false,
      true,   //11
      false, 
      true,   //13
      false,  
      false,
      false,
      true,   //17
      false,
      true,   //19
      false,
      false
      } {
  std::vector<unsigned int> row0 {0, 1};
  popTable.push_back(row0);
  for (auto i = 1; i < 21; i++) {
    std::vector<unsigned int> nextRow;
    for (auto row : popTable) {
      for (auto column : row)
        nextRow.push_back(column + 1); 
    }
    popTable.push_back(nextRow);
  }
}
