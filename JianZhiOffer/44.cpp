#include "../utils.h"

int findNthDigit(int n) {
  if (n <= 9) {
    return n;
  }
  n -= 10;
  int base = 10, bit = 2;

  while (n / 9 >= base * bit) {
    n -= base * bit * 9;
    base *= 10;
    ++bit;
  }
  int cur = base + n / bit;
  return to_string(cur)[n % (bit)] - '0';
}