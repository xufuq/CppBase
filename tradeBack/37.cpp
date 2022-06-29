#include "../utils.h"

bool IsAvailable(vector<vector<char>>& board, int row, int col, char val) {
  for (int i = 0; i < 9; ++i) {
    if (board[i][col] == val || board[row][i] == val) {
      return false;
    }
  }
  int start_row = row / 3, start_col = col / 3;
  for (int i = 3 * start_row; i < 3 * (start_row + 1); ++i) {
    for (int j = 3 * start_col; j < 3 * (start_col + 1); ++j) {
      if (board[i][j] == val) {
        return false;
      }
    }
  }
  return true;
}

vector<char> getUsableNUm(vector<vector<char>>& board, int row, int col) {
  unordered_set<char> used;
  vector<char> result;
  for (int i = 0; i < 9; ++i) {
    used.insert(board[i][col]);
    used.insert(board[row][i]);
  }
  int start_row = row / 3, start_col = col / 3;
  for (int i = 3 * start_row; i < 3 * (start_row + 1); ++i) {
    for (int j = 3 * start_col; j < 3 * (start_col + 1); ++j) {
      used.insert(board[i][j]);
    }
  }
  for (char k = '1'; k <= '9'; ++k) {
    if (used.count(k) == 0) {
      result.push_back(k);
    }
  }
  return result;
}

bool solveSudoku(vector<vector<char>>& board, int start_row) {
  for (int i = start_row; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] == '.') {
        vector<char> usable = getUsableNUm(board, i, j);
        for (auto& k : usable) {
          board[i][j] = k;
          if (solveSudoku(board, i)) {
            return true;
          }
          board[i][j] = '.';
        }
        return false;
      }
    }
  }
  return true;
}

void solveSudoku(vector<vector<char>>& board) { solveSudoku(board, 0); }