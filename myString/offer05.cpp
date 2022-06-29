#include "../utils.h"

string replaceSpace(string s) {
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == ' ') {
      s.replace(s.begin() + i, s.begin() + i + 1, "%20");
    }
  }
  return s;
}