#include "../utils.h"

bool IsIncrease(int n) {
  string str = to_string(n);
  for (int i = 1; i < str.length(); ++i) {
    if (str[i] < str[i - 1]) {
      return false;
    }
  }
  return true;
}

int monotoneIncreasingDigits(int n) {
  while (1) {
    string str = to_string(n);
    int len = str.length();
    if (len == 1) {
      return n;
    }
    for (int i = 0; i < len - 1; ++i) {
      if (str[i] > str[i + 1]) {
        n = n - n % (int)(pow(10, len - i - 1)) - 1;
        break;
      }
      if (i == len - 2) {
        return n;
      }
    }
  }
  return n;
}