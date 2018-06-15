#include <vector>

#include <iostream>

using std::vector;

class Solution {
public:
  std::size_t pow(std::size_t k, std::size_t n) {
    std:size_t product = 1;
    for (auto i = 0; i < n; i ++)
      product *= k;
    return product;
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    // set up the environment first
    vector<vector<int>> result;
    // get the size
    std::size_t n = nums.size();
    if (n == 0) {
      result.push_back(nums);
      return result;
    }
    // get the vector sorted
    vector<int> nums_r = nums; // make a copy
    std::sort(nums_r.begin(), nums_r.end());
    // get into the loop
    std::size_t numSubsets = pow(2, n);
    std::size_t mask = 0;
    while (mask < numSubsets) {
      std::size_t index = 0;
      std::size_t indexMask = 1;
      vector<int> item;
      while (index < n) {
        if (indexMask & mask)
          item.push_back(nums_r[index]);
        index++;
        indexMask <<= 1;
      }
      result.push_back(item);
      mask++;
    }

    return result;
    
  }
  vector<vector<int>> insert(vector<vector<int>> &perms, int k) {
    vector<vector<int>> result;
    for (auto vector_of_int : perms) {
      for (auto i = vector_of_int.begin(); i <= vector_of_int.end(); i++) {
        vector<int> temp;
        for (auto j = vector_of_int.begin(); j < i; j++) {
          temp.push_back(*j);
        }
        temp.push_back(k);
        for (auto j = i; j < vector_of_int.end(); j++) {
          temp.push_back(*j);
        }
        result.push_back(temp);
      }
    }
    return result;
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) return result;
    if (nums.size() == 1) {
      result.push_back(nums);
      return result;
    }
    vector<int> temp = nums;
    int shave = temp.back();
    temp.pop_back();
    vector<vector<int>> prev = permute(temp);
    result = insert(prev, shave); 
    return result;
  }
};

int main () {
  Solution s;
  vector<int> nums0;
  vector<int> nums1 {1};
  vector<int> nums2 {1,2};
  vector<int> nums3 {1,2,3};
  vector<int> nums4 {1,2,3,4};

  vector<vector<int>> subsets0 = s.subsets(nums0);
  vector<vector<int>> subsets1 = s.subsets(nums1);
  vector<vector<int>> subsets2 = s.subsets(nums2);
  vector<vector<int>> subsets3 = s.subsets(nums3);
  vector<vector<int>> subsets4 = s.subsets(nums4);

  for (auto vector_of_int : subsets0) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }


  for (auto vector_of_int : subsets1) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : subsets2) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : subsets3) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

#if 0
  vector<vector<int>> perms0 = s.permute(nums0);
  vector<vector<int>> perms1 = s.permute(nums1);
  vector<vector<int>> perms2 = s.permute(nums2);
  vector<vector<int>> perms3 = s.permute(nums3);
  vector<vector<int>> perms4 = s.permute(nums4);

  for (auto vector_of_int : perms0) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : perms1) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : perms2) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : perms3) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }

  for (auto vector_of_int : perms4) {
    for (auto value : vector_of_int) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
#endif
  return 0;
}