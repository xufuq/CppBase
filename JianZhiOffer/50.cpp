#include "../utils.h"

char firstUniqChar(string s) {
  vector<int> counts(26, 0);
  for (auto &c : s) {
    ++counts[c - 'a'];
  }
  for (auto &c : s) {
    if (counts[c - 'a'] == 1) {
      return c;
    }
  }
  return ' ';
}