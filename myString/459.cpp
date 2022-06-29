#include "../utils.h"

bool repeatedSubstringPattern(string s) {
  int len1 = s.length();
  if (len1 == 1) {
    return false;
  }
  vector<int> kmp(len1, -1);
  int last = -1;
  for (int i = 1; i < len1; ++i) {
    last = kmp[i - 1];
    while (1) {
      if (s[i] == s[last + 1]) {
        kmp[i] = last + 1;
        break;
      } else if (last == -1) {
        break;
      } else {
        last = kmp[last];
      }
    }
  }
  last = kmp[len1 - 1] + 1;
  int first = len1 - last;
  if (last / first > 0 && last % first == 0) {
    return true;
  } else {
    return false;
  }
}