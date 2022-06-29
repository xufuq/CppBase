#include "../utils.h"

Node* connect(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  queue<Node*> que;
  que.push(root);
  que.push(nullptr);
  Node* cur;
  while (1) {
    cur = que.front();
    que.pop();
    if (cur) {
      cur->next = que.front();
      if (cur->left) que.push(cur->left);
      if (cur->right) que.push(cur->right);
    } else {
      if (que.empty()) {
        break;
      }
      que.push(nullptr);
    }
  }
  return root;
}