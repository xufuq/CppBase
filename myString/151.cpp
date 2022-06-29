#include "../utils.h"
string reverseWords(string s) {
  while (s.back() == ' ') {
    s.pop_back();
  }
  int n = s.size(), start = 0;
  for (int i = n - 1; i > 0; --i) {
    if (s[i] == ' ' && s[i - 1] == ' ') {
      s.replace(i, 1, "");
    }
  }
  n = s.size();
  if (n > 0 && s[0] == ' ') {
    s.replace(0, 1, "");
  }
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ') {
      reverse(s.begin() + start, s.begin() + i);
      start = i + 1;
    }
  }
  reverse(s.begin() + start, s.end());
  return s;
}

// 直接替换的话复杂度过高

string reverseWords(string s) {
  int new_start = 0, fast = 0, slow = 0, n = s.size();
  while (fast < n) {
    while (slow < n && s[slow] == ' ') {
      ++slow;
    }
    fast = slow;
    while (fast < n && s[fast] != ' ') {
      ++fast;
    }
    while (slow < fast) {
      s[new_start++] = s[slow++];
    }
    s[new_start++] = ' ';
  }
  new_start -= 1;
  s.resize(new_start);
  while (s.back() == ' ') {
    s.pop_back();
  }

  reverse(s.begin(), s.end());
  slow = 0;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ') {
      reverse(s.begin() + slow, s.begin() + i);
      slow = i + 1;
    }
  }
  reverse(s.begin() + slow, s.end());

  return s;
}