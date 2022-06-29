#include "../utils.h"

// 贪心算法，找出的3越多越好
int cuttingRope(int n) {
  int base = 1000000007;
  if (n == 2) return 1;
  int res = 1;
  if (n % 3 == 1) {
    res *= 4;
    n -= 4;
  }
  if (n % 3 == 2) {
    res *= 2;
    n -= 2;
  }
  while (n) {
    res *= 3;
    res /= base;
    n -= 3;
  }
  return res;
}