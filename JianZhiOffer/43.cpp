#include "../utils.h"

int countDigitOne(int n) {
  int base = 10;
  int result = 0;
  result += n / base;
  if (n % base > 0) {
    ++result;
  }
  while (n >= base) {
    int pre = n / base;
    if (pre % 10 > 1) {
      pre = pre / 10 + 1;
    } else {
      pre = pre / 10;
    }
    result += pre * base;
    if (n / base % 10 == 1) {
      result += n % base + 1;
    }
    if (base == 1000000000) {
      break;
    }
    base *= 10;
  }
  return result;
}