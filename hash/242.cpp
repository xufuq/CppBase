#include "../utils.h"

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) {
    return false;
  }
  vector<int> count(26, 0);
  for (auto &c : s) {
    ++count[c - 'a'];
  }
  for (auto &c : t) {
    --count[c - 'a'];
  }
  for (auto &n : count) {
    if (n != 0) {
      return false;
    }
  }
  return true;
}