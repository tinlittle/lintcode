#include <string>

class Solution {
public:
    void rotateString(std::string &str, int offset) {
      if (str.empty()) return;
      offset %= str.size();
      while (offset--) {
        char extra = str.back();
        std::string::reverse_iterator right = str.rbegin();
        std::string::const_reverse_iterator left = str.crbegin();
        left++;
        while (left != str.crend())
          *right++ = *left++;
        str.front() = extra;
      }
    }
};