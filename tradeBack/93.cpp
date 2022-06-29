#include "../utils.h"

void restoreIpAddresses(string &s, vector<string> &result, vector<string> &path,
                        int start_index) {
  if (path.size() == 4) {
    if (start_index == s.length()) {
      string str = path[0];
      for (int i = 1; i < 4; ++i) {
        str += "." + path[i];
      }
      result.push_back(str);
    }
    return;
  }
  if (start_index >= s.length()) {
    return;
  }
  if (s[start_index] == '0') {
    path.push_back("0");
    restoreIpAddresses(s, result, path, start_index + 1);
    path.pop_back();
  } else {
    for (int i = 1; i < 4 && start_index + i - 1 < s.length(); ++i) {
      string str = s.substr(start_index, i);
      if (atoi(str.data()) <= 255) {
        path.push_back(str);
        restoreIpAddresses(s, result, path, start_index + i);
        path.pop_back();
      }
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  vector<string> result, path;
  restoreIpAddresses(s, result, path, 0);
  return result;
}