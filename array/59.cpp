#include "../utils.h"

vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> result(n, vector<int>(n, 0));
  int left = 0, up = 0, right = n - 1, down = n - 1;
  int cur = 1;
  while (cur <= n * n) {
    if (left == right) {
      result[left][up] = cur++;
    } else {
      int pos = left;
      while (pos < right) {
        result[up][pos] = cur++;
        ++pos;
      }
      pos = up;
      while (pos < down) {
        result[pos][right] = cur++;
        ++pos;
      }
      pos = right;
      while (pos > left) {
        result[down][pos] = cur++;
        --pos;
      }
      pos = down;
      while (pos > up) {
        result[pos][left] = cur++;
        --pos;
      }
      ++left;
      ++up;
      --right;
      --down;
    }
  }
  return result;
}
