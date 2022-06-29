#include "../utils.h"

// kmp
int strStr(string haystack, string needle) {
  int len1 = haystack.length(), len2 = needle.length();
  if (len2 == 0) {
    return 0;
  }
  vector<int> kmp(len2, -1);
  int last = -1;
  for (int i = 1; i < len2; ++i) {
    last = kmp[i - 1];
    while (1) {
      if (needle[i] == needle[last + 1]) {
        kmp[i] = last + 1;
        break;
      } else if (last == -1) {
        break;
      } else {
        last = kmp[last];
      }
    }
  }
  last = -1;
  for (int i = 0; i < len1; ++i) {
    while (1) {
      if (haystack[i] == needle[last + 1]) {
        ++last;
        break;
      } else if (last != -1) {
        last = kmp[last];
      } else {
        break;
      }
    }
    if (last == len2 - 1) {
      return i + 1 - len2;
    }
  }
  return -1;
}