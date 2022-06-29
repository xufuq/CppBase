#include "../utils.h"

// struct cmp {
static bool cmp(vector<int>& lhs, vector<int>& rhs) {
  if (lhs[0] < rhs[0]) {
    return true;
  } else if (lhs[0] == rhs[0] && lhs[1] > rhs[1]) {
    return true;
  }
  return false;
}
// };

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
  int n = people.size();
  vector<vector<int>> result(n, vector<int>(2, -1));
  sort(people.begin(), people.end(), cmp);

  for (int i = 0; i < n; ++i) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
      if (result[j][0] == -1) {
        if (people[i][1] == count) {
          result[j] = people[i];
          break;
        } else {
          ++count;
        }
      }
    }
  }
  return result;
}