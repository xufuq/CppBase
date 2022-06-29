#include "../utils.h"

int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int s_index = 0, g_index = 0;
  for (; g_index < g.size();) {
    while (s_index < s.size()) {
      if (s[s_index] >= g[g_index]) {
        ++s_index;
        ++g_index;
        break;
      } else {
        ++s_index;
      }
    }
    if (s_index == s.size()) {
      return g_index;
    }
  }
  return g_index;
}