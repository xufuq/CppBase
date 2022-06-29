#include "../utils.h"

bool isPot(string &s, int start_index, int end_index) {
  bool pot = false;
  for (int i = start_index; i <= end_index; ++i) {
    if (isdigit(s[i])) {
      continue;
    } else if (s[i] == '+' || s[i] == '-') {
      if (i == start_index && i < end_index &&
          (isdigit(s[i + 1]) || s[i + 1] == '.')) {
        continue;
      } else {
        return false;
      }
    } else if (s[i] == '.' && pot == false) {
      pot = true;
      if ((i > start_index && isdigit(s[i - 1])) ||
          (i < end_index && isdigit(s[i + 1]))) {
        continue;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return pot;
}

bool isFull(string &s, int start_index, int end_index) {
  if (start_index > end_index) {
    return false;
  }
  for (int i = start_index; i <= end_index; ++i) {
    if (isdigit(s[i])) {
      continue;
    } else if (s[i] == '+' || s[i] == '-') {
      if (i == start_index && i < end_index && isdigit(s[i + 1])) {
        continue;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
}

bool isNumber(string s) {
  int start = 0, end = s.length() - 1;
  while (start <= end && s[start] == ' ') {
    ++start;
  }
  while (start <= end && s[end] == ' ') {
    --end;
  }
  int E_index = -1;
  for (int i = start; i <= end; ++i) {
    if (s[i] == 'E' || s[i] == 'e') {
      E_index = i;
      break;
    }
  }
  if (E_index == -1) {
    return isPot(s, start, end) || isFull(s, start, end);
  } else {
    return (isPot(s, start, E_index - 1) || isFull(s, start, E_index - 1)) &&
           isFull(s, E_index + 1, end);
  }
}