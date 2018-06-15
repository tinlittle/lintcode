#include <vector>
#include <deque>
#include <array>
#include <functional>

class UglyNumber {
public:
  long long getNthUglyNumber(int n);
  long long getNthUglyNumber2(int n);
public: 
  UglyNumber();
  ~UglyNumber() {};
private:
  int listCount;
  std::vector<long long> list;
  std::deque<long long> x2List;
  std::deque<long long> x3List;
  std::deque<long long> x5List;

  bool isUgly(long long n);
  void buildAuthorativeList();
  
  std::array<long long, 1000> authorativeList;
  int aListCount;


};
