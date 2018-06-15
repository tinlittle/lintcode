#include "fib.h"

long long fibonacci::getFib(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  long long fn_1 = 1, fn_2 = 1;
  long long fn;
  int i = 2;
  while (i <= n) {
    fn = fn_1 + fn_2;
    fn_2 = fn_1;
    fn_1 = fn;
    i++;
  }
  return fn;
}