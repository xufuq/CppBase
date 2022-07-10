#include "../utils.h"

int strToInt(string str) {
  if (str.empty()) {
    return 0;
  }
  bool sign_num = true;
  int result = 0;
  bool be_sign = true;
  int i = 0;
  while (i < str.length() && str[i] == ' ') {
    ++i;
  }
  for (; i < str.length(); ++i) {
    char c = str[i];
    if (c == '+' || c == '-') {
      if (be_sign) {
        be_sign = false;
        sign_num = c == '+' ? true : false;
      } else {
        break;
      }
    } else if (isdigit(c)) {
      be_sign = false;
      if (result < INT32_MAX / 10) {
        result = result * 10 + (c - '0');
      } else if (result == INT32_MAX / 10) {
        if (sign_num) {
          if (INT32_MAX % 10 > (c - '0')) {
            result = result * 10 + (c - '0');
          } else {
            return INT32_MAX;
          }
        } else {
          if (abs(INT32_MIN % 10) > (c - '0')) {
            result = result * 10 + (c - '0');
          } else {
            return INT32_MIN;
          }
        }
      } else {
        return sign_num ? INT32_MAX : INT32_MIN;
      }
    } else {
      break;
    }
  }
  return sign_num ? result : (-result);
}