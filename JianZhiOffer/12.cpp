#include "../utils.h"

bool dfs(vector<vector<char>>& board, string& word, int index, int row,
         int col) {
  if (index == word.length()) {
    return true;
  }
  if (row + 1 >= 0 && row + 1 < board.size() &&
      board[row + 1][col] == word[index]) {
    board[row + 1][col] = -board[row + 1][col];
    if (dfs(board, word, index + 1, row + 1, col)) {
      return true;
    }
    board[row + 1][col] = -board[row + 1][col];
  }
  if (row - 1 >= 0 && row - 1 < board.size() &&
      board[row - 1][col] == word[index]) {
    board[row - 1][col] = -board[row - 1][col];
    if (dfs(board, word, index + 1, row - 1, col)) {
      return true;
    }
    board[row - 1][col] = -board[row - 1][col];
  }
  if (col + 1 >= 0 && col + 1 < board[0].size() &&
      board[row][col + 1] == word[index]) {
    board[row][col + 1] = -board[row][col + 1];
    if (dfs(board, word, index + 1, row, col + 1)) {
      return true;
    }
    board[row][col + 1] = -board[row][col + 1];
  }
  if (col - 1 >= 0 && col - 1 < board[0].size() &&
      board[row][col - 1] == word[index]) {
    board[row][col - 1] = -board[row][col - 1];
    if (dfs(board, word, index + 1, row, col - 1)) {
      return true;
    }
    board[row][col - 1] = -board[row][col - 1];
  }
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      if (board[i][j] == word[0]) {
        board[i][j] = -board[i][j];
        if (dfs(board, word, 1, i, j)) {
          return true;
        }
        board[i][j] = -board[i][j];
      }
    }
  }
  return false;
}