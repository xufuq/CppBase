#include "../utils.h"

void letterCombinations(string &digits, int index,
                        unordered_map<char, string> &dig_al,
                        vector<string> &result, string &path) {
  if (index == digits.length()) {
    result.push_back(path);
    return;
  } else {
    for (int i = 0; i < dig_al[digits[index]].size(); ++i) {
      path.push_back(dig_al[digits[index]][i]);
      letterCombinations(digits, index + 1, dig_al, result, path);
      path.pop_back();
    }
  }
}
vector<string> letterCombinations(string digits) {
  vector<string> result;
  if (digits.length() == 0) {
    return result;
  }
  string path;
  unordered_map<char, string> dig_al;
  dig_al['2'] = "abc";
  dig_al['3'] = "def";
  dig_al['4'] = "ghi";
  dig_al['5'] = "jkl";
  dig_al['6'] = "mno";
  dig_al['7'] = "pqrs";
  dig_al['8'] = "tuv";
  dig_al['9'] = "wxyz";
  letterCombinations(digits, 0, dig_al, result, path);
  return result;
}