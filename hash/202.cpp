#include "../utils.h"

bool isHappy(int n) {
  int sum = 0;
  int bit_n;
  unordered_set<int> count;
  while (n != 1 && count.count(n) == 0) {
    count.insert(n);
    while (n != 0) {
      bit_n = n % 10;
      n /= 10;
      sum += bit_n * bit_n;
    }
    n = sum;
    sum = 0;
  }
  if (n == 1) {
    return true;
  } else {
    return false;
  }
}