#include "../utils.h"

int minDistance(string word1, string word2) {
  int n1 = word1.length(), n2 = word2.length();
  if (n1 == 0) {
    return n2;
  } else if (n2 == 0) {
    return n1;
  }
  vector<vector<int>> dp(n1, vector<int>(n2, 0));
  int noequal = 1;
  for (int i = 0; i < n1; ++i) {
    if (word1[i] == word2[0]) {
      noequal = 0;
      dp[i][0] = i;
    } else {
      dp[i][0] = i + noequal;
    }
  }
  noequal = 1;
  for (int i = 0; i < n2; ++i) {
    if (word1[0] == word2[i]) {
      noequal = 0;
      dp[0][i] = i;
    } else {
      dp[0][i] = i + noequal;
    }
  }

  for (int i = 1; i < n1; ++i) {
    for (int j = 1; j < n2; ++j) {
      if (word1[i] == word2[j]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      }
    }
  }
  for (auto &row : dp) {
    for (auto &col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
  return dp[n1 - 1][n2 - 1];
}

int main(int agrc, char **argv) {
  cout << argv[1] << " " << argv[2] << endl;
  return minDistance(argv[1], argv[2]);
}