#include "../utils.h"

bool IsAvailable(vector<string> &path, int row, int col, int n) {
  for (int i = 0; i < row; ++i) {
    if (path[i][col] == 'Q') {
      return false;
    }
  }
  for (int i = 1; row - i >= 0 && col - i >= 0; ++i) {
    if (path[row - i][col - i] == 'Q') {
      return false;
    }
  }
  for (int i = 1; row - i >= 0 && col + i < n; ++i) {
    if (path[row - i][col + i] == 'Q') {
      return false;
    }
  }
  return true;
}

void solveNQueens(int n, int cur_row, vector<string> &path,
                  vector<vector<string>> &result) {
  if (cur_row == n) {
    result.push_back(path);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (IsAvailable(path, cur_row, i, n)) {
      path.push_back(string(i, '.') + "Q" + string(n - i - 1, '.'));
      solveNQueens(n, cur_row + 1, path, result);
      path.pop_back();
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> result;
  vector<string> path;
  solveNQueens(n, 0, path, result);
  return result;
}