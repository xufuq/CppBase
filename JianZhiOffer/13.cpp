#include "../utils.h"

int getBitSum(int row, int col) {
  int result = 0;
  while (row > 0) {
    result += row % 10;
    row /= 10;
  }
  while (col > 0) {
    result += col % 10;
    col /= 10;
  }
  return result;
}

void dfs(int m, int n, int k, int row, int col, vector<vector<int>> &used,
         vector<int> &nums, int &result) {
  for (int i = 0; i < 2; ++i) {
    int cur_row = row + nums[i], cur_col = col + nums[i];
    if (cur_row >= 0 && cur_row < m) {
      if (used[cur_row][col] && getBitSum(cur_row, col) <= k) {
        ++result;
        used[cur_row][col] = false;
        dfs(m, n, k, cur_row, col, used, nums, result);
      }
    }
    if (cur_col >= 0 && cur_col < n) {
      if (used[row][cur_col] && getBitSum(row, cur_col) <= k) {
        ++result;
        used[row][cur_col] = false;
        dfs(m, n, k, row, cur_col, used, nums, result);
      }
    }
  }
}

int movingCount(int m, int n, int k) {
  vector<int> nums{-1, 1};
  vector<vector<int>> used(m, vector<int>(n, true));
  int result = 1;
  used[0][0] = false;
  dfs(m, n, k, 0, 0, used, nums, result);
  return result;
}