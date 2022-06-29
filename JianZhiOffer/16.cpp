#include "../utils.h"

double myPow(double x, int n) {
  if (n == 0) {
    return 1;
  }
  bool my_sign = n > 0;
  n = abs(n);
  double result = 1;
  if (n > 0) {
    while (n > 0) {
      if (n % 2) {
        result *= x;
        n -= 1;
      } else {
        x *= x;
        n /= 2;
      }
    }
  } else {
    while (n < 0) {
      if (n % 2) {
        result *= x;
        n += 1;
      } else {
        x *= x;
        n /= 2;
      }
    }
  }
  return my_sign ? result : (1 / result);
}