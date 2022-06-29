#include "../utils.h"

int lengthOfLastWord(string s) {
  int end = s.size() - 1, start = end;
  while (s[end] == ' ') {
    --end;
  }
  start = end;
  while (start >= 0 && s[start] != ' ') {
    --start;
  }
  return end - start;
}