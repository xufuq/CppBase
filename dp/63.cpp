#include "../utils.h"
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int row = obstacleGrid.size(), col = obstacleGrid[0].size();
  if (obstacleGrid[0][0] == 0) {
    obstacleGrid[0][0] = 1;
  } else {
    return 0;
  }
  for (int i = 1; i < col; ++i) {
    if (obstacleGrid[0][i] == 1) {
      obstacleGrid[0][i] = 0;
    } else {
      obstacleGrid[0][i] = obstacleGrid[0][i - 1];
    }
  }
  for (int i = 1; i < row; ++i) {
    if (obstacleGrid[i][0] == 1) {
      obstacleGrid[i][0] = 0;
    } else {
      obstacleGrid[i][0] = obstacleGrid[i - 1][0];
    }
  }
  for (int i = 1; i < row; ++i) {
    for (int j = 1; j < col; ++j) {
      if (obstacleGrid[i][j] == 1) {
        obstacleGrid[i][j] = 0;
      } else {
        obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
      }
    }
  }
  return obstacleGrid[row - 1][col - 1];
}