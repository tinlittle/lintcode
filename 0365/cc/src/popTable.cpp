#include <vector>

#include "popTable.h"


std::vector<int> bitMath::PopCount(int num) {
  std::vector<int> popCountVector;
  if (num < 0)
    return popCountVector;

  // start with 0x00 and 0x01
  popCountVector.push_back(0);
  if (num == 0)
    return popCountVector;
  popCountVector.push_back(1);
  if (num == 1)
    return popCountVector;

  size_t currentIndex = 2;
  do {
    size_t size = popCountVector.size();
    for (size_t i = 0; i < size && currentIndex <= num; i++) {
      popCountVector.push_back(popCountVector[i] + 1);
      currentIndex++;
    }
  } while (currentIndex <= num);

  return popCountVector;
}