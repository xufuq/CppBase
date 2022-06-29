#include "../utils.h"

void permutation(string &s, vector<bool> &used, string &path,
                 unordered_set<string> &res) {
  if (path.size() == s.size()) {
    res.insert(path);
    return;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (!used[i]) {
      used[i] = true;
      path.push_back(s[i]);
      permutation(s, used, path, res);
      path.pop_back();
      used[i] = false;
    }
  }
}

vector<string> permutation(string s) {
  unordered_set<string> res;
  string path;
  vector<bool> used(s.size(), false);
  permutation(s, used, path, res);
  return vector<string>(res.begin(), res.end());
}