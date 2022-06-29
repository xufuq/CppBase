#include "../utils.h"

bool reverse_k(string &s, int start, int end) {
  while (start < end) {
    swap(s[start], s[end]);
    ++start, --end;
  }
  return true;
}

string reverseStr(string s, int k) {
  int n = s.size(), start = 0;
  while (start < n) {
    if ((start + k) < n) {
      reverse_k(s, start, start + k - 1);
    } else {
      reverse_k(s, start, n - 1);
    }
    start += 2 * k;
  }
  return s;
}