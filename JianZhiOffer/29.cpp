#include "../utils.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  if (rows == 0) {
    return vector<int>();
  }
  int cols = matrix[0].size();
  vector<int> result(rows * cols, 0);
  int left = 0, right = cols - 1, up = 0, down = rows - 1;
  int i = 0;
  while (i < (rows * cols)) {
    for (int j = left; j <= right; ++j) {
      result[i++] = matrix[up][j];
    }
    for (int j = up + 1; j < down; ++j) {
      result[i++] = matrix[j][right];
    }
    if (down > up) {
      for (int j = right; j >= left; --j) {
        result[i++] = matrix[down][j];
      }
    }
    if (right > left) {
      for (int j = down - 1; j > up; --j) {
        result[i++] = matrix[j][left];
      }
    }
    ++up, ++left, --down, --right;
  }
  return result;
}