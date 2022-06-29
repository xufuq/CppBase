#include "../utils.h"

// from left, down
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();
  if (n == 0) {
    return false;
  }
  int m = matrix[0].size();
  int i = n - 1, j = 0;
  while (i >= 0 && j < m) {
    if (matrix[i][j] < target) {
      ++j;
    } else if (matrix[i][j] > target) {
      --i;
    } else {
      return true;
    }
    //   cout << i << "  "<<j << endl;
  }
  return false;
}