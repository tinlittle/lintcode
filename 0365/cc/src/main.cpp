#include <iostream>
#include <vector>

#include "popTable.h"

int main() {

  std::vector<int> popTable = bitMath::PopCount(15);

  for (size_t i = 0; i < popTable.size(); i++)
    std::cout << popTable[i] << std::endl;

  return 0;
}