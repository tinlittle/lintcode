#include <vector>
#include <utility>

#include <iostream>

template <std::size_t faces>
class Solution_T {
public:
  long long numOfCases(int n) {
    long long num = 1;
    for (auto i = 0; i < n; i++) num *= faces;
    return num;
  }
  int lowComs(int n) {
    return n;
  }
  int highComs(int n) {
    return faces * n;
  }
  std::vector<std::pair<int, long long>> dicesSumCounts(int n) {
    typedef std::vector<std::pair<int, long long>> OccurTable;
    std::vector<OccurTable> table_v;
    // round 1
    OccurTable table;
    for (auto i = 1; i <= faces; i++) {
      table.push_back(std::make_pair(i, 1));
    }
    table_v.push_back(table);
    long long totalOcurrances = 0;
    for (auto tally : table) {
      totalOcurrances += tally.second;
    }
    assert (totalOcurrances == numOfCases(1));

    auto occurancesInRound = [&table_v] (int round, int row) -> long long {
      auto table = table_v[round - 1];
      auto pair = std::find_if(table.begin(), table.end(),
          [row] (const std::pair<int, long long> pair ) {return pair.first == row;}
      );
      if (pair != table.end())
        return (*pair).second;
      else
        return 0;
    };
    
    // round 2
    for (auto round = 2; round <= n; round++) {
      table.clear();
      for (int row = lowComs(round - 1); row <= highComs(round - 1); row++) {
        for (int column = 1; column <= faces; column++) {
          int sum = row + column;
          long long occurances = occurancesInRound(round - 1, row); // need to look up in the occurance table from last round
          auto cell_pair = std::find_if(table.begin(), table.end(), 
                [sum] (const std::pair<int, long long> pair) {return pair.first == sum;}
                );
          if (cell_pair != table.end())
            (*cell_pair).second += occurances;
          else {
            table.push_back(std::make_pair(sum, occurances));
          }
        }
      }
      table_v.push_back(table);
      totalOcurrances = 0;
      for (auto tally : table) {
        totalOcurrances += tally.second;
      }
      assert (totalOcurrances == numOfCases(round));
    }
    
    return table_v[n-1];
  }
  std::vector<std::pair<int, double>> dicesSum(int n) {
    std::vector<std::pair<int, long long>> cTable;
    cTable = dicesSumCounts(n);
    std::vector<std::pair<int, double>> dTable;
    long long total = numOfCases(n);
    for (auto cPair : cTable) {
      double odds = cPair.second * 1.0;
      odds /= total;
      dTable.push_back(std::make_pair(cPair.first, odds));
    }
    return dTable;
  }
};

typedef Solution_T<5> Solution;

int main() {
  Solution s;
  std::vector<std::pair<int, long long>> table;


  table = s.dicesSumCounts(20);

  for (auto a_pair : table) {
    std::cout << a_pair.first << " : " << a_pair.second << std::endl;
  }

  std::vector<std::pair<int, double>> dTable;
  dTable = s.dicesSum(14);
  for (auto a_pair : dTable) {
    std::cout << a_pair.first << " : " << a_pair.second << std::endl;
  }


  return 0;
}