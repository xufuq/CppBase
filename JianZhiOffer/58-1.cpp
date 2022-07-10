#include "../utils.h"

string reverseWords(string s) {
  reverse(s.begin(), s.end());
  string result;
  istringstream is(s);
  string tmp;

  while (is >> tmp) {
    reverse(tmp.begin(), tmp.end());
    result += tmp + " ";
  }
  result.pop_back();
  return result;
}