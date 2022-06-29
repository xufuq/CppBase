#include "../utils.h"

bool isCircle(string &s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end - 1]) {
      return false;
    }
    ++start;
    --end;
  }
  return true;
}

void partition(string &s, vector<vector<string>> &result, vector<string> &path,
               int start) {
  if (start == s.length()) {
    result.push_back(path);
    return;
  } else if (start > s.length()) {
    return;
  }

  for (int i = start; i < s.length(); ++i) {
    if (s[i] == s[start] && isCircle(s, start, i + 1)) {
      path.push_back(s.substr(start, i - start + 1));
      partition(s, result, path, i + 1);
      path.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> result;
  vector<string> path;
  partition(s, result, path, 0);
  return result;
}