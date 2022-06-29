#include "../utils.h"

vector<int> partitionLabels(string s) {
  vector<int> result;
  vector<vector<int>> vec(26, vector<int>(2, -1));
  int len = s.length();
  for (int i = 0; i < len; ++i) {
    if (vec[s[i] - 'a'][0] == -1) {
      vec[s[i] - 'a'][0] = i;
    }
    vec[s[i] - 'a'][1] = i;
  }
  int start = 0, end = 0;
  for (int i = 0; i < len; ++i) {
    if (i > end) {
      result.push_back(end - start + 1);
      start = i, end = i;
    }
    end = max(end, vec[s[i] - 'a'][1]);
  }
  result.push_back(end - start + 1);
  return result;
}