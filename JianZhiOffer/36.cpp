#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

Node* treeToDoublyList(Node* root) {
  if (!root) {
    return root;
  }
  stack<Node*> st;
  Node *head = nullptr, *cur = root;
  Node* double_list_cur = nullptr;
  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;
    } else {
      cur = st.top();
      st.pop();
      {
        if (head == nullptr) {
          head = cur;
          double_list_cur = head;
        } else {
          double_list_cur->right = cur;
          cur->left = double_list_cur;
          double_list_cur = cur;
        }
      }
      cur = cur->right;
    }
  }
  double_list_cur->right = head;
  head->left = double_list_cur;
  return head;
}