
#include "uglyQueue.h"

UglyNumber::UglyNumber() {
  list.push_back(1);
  x2List.push_back(2);
  x3List.push_back(3);
  x5List.push_back(5);
  listCount = 1;
  aListCount = 0;
  buildAuthorativeList();
}

bool UglyNumber::isUgly(long long n) {
  while (n % 2 == 0)
    n /= 2;
  while (n % 3 == 0)
    n /= 3;
  while (n % 5 == 0)
    n /= 5;
  return (n == 1) ? true:false;
}

void UglyNumber::buildAuthorativeList() {
  std::size_t alistCount = 0;
  long long candidate = 1;
  while (alistCount < authorativeList.size()) {
    if (isUgly(candidate)) {
      authorativeList[alistCount++] = candidate;
    }
    candidate++;
  }
}

long long UglyNumber::getNthUglyNumber(int n) {
 while (listCount < n) {
    // find the vector that currently holds the smallest item
    std::deque<long long>* 
      v = std::min<std::deque<long long>*>({&x2List, &x3List, &x5List}, 
                      [](/*std::deque<long long> * */ auto v1, std::deque<long long> *v2) -> bool {
                        return v1->front() < v2->front();
                      }
                      );
    long long nextUgly = v->front();
    
    if (nextUgly == x2List.front())
      x2List.pop_front();
    if (nextUgly == x3List.front())
      x3List.pop_front();
    if (nextUgly == x5List.front())
      x5List.pop_front();

    //v->pop_front();
    list.push_back(nextUgly);
    x2List.push_back(nextUgly * 2);
    x3List.push_back(nextUgly * 3);
    x5List.push_back(nextUgly * 5);

    listCount++;
  }
  return list[n-1];
}

long long UglyNumber::getNthUglyNumber2(int n) {

  int x2index = 0, x3index = 0, x5index = 0;
  while (listCount < n) {
    // list contains ugly numbers accumulated so far
    // list starts with one ugly number -- 1
    // all ugly numbers coming after this would be a multiple of 2, 3, or 5 of 
    // existing ugly numbers
    // the * 2, * 3, * 5 index store the index into existing ugly numbers
    // those indices are updated in such way that the ugly number they point to
    // multiply the respective factor (2, 3, 5) would be greater than the current
    // known biggest ugly number
    // theose indices thus represent the 3 candidates for the next ugly number
    long long nextUgly = std::min({list[x2index] * 2, list[x3index] * 3, list[x5index] * 5});
    list.push_back(nextUgly);
    while (list[x2index] * 2 <= nextUgly)
      x2index++;
    while (list[x3index] * 3 <= nextUgly)
      x3index++;
    while (list[x5index] * 5 <= nextUgly)
      x5index++;    

    listCount++;
  }
  return list[n-1];
}