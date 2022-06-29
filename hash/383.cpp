#include "../utils.h"

bool canConstruct(string ransomNote, string magazine) {
  vector<int> count(26, 0);
  for (auto &c : magazine) {
    ++count[c - 'a'];
  }
  for (auto &c : ransomNote) {
    --count[c - 'a'];
    if (count[c - 'a'] < 0) {
      return false;
    }
  }
  return true;
}