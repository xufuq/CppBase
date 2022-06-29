#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "math.h"
#include "stdio.h"
#include "time.h"

using namespace std;

inline std::string StringUtcTime() {
  time_t t = time(NULL);
  struct tm *tmp = localtime(&t);
  std::array<char, 32> data;
  strftime(data.data(), 32, "%Y-%m-%d %H:%M:%S", tmp);
  return std::string(data.data());
}

#define info_printf(fmt, ...)                                              \
  printf("%s %s::%s[%d]:" fmt, StringUtcTime().data(), __FILE__, __func__, \
         __LINE__, ##__VA_ARGS__)

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};