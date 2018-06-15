#include "fib.h"

#include <iostream>

int main () {
  long long f45 = fibonacci::getFib(45);

  std::cout << f45 << std::endl;

  while (true) {
    unsigned short i;
    std::cout << "a number below 100: ";
    std::cin >> i;
    std::cout << "fib: " << fibonacci::getFib(i) << std::endl;

  }
  return 0;
}