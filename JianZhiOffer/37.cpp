#include "../utils.h"

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  vector<string> res;
  string result;
  if (!root) {
    return result;
  }

  queue<TreeNode*> que;
  TreeNode* cur = root;
  que.push(cur);
  while (!que.empty()) {
    cur = que.front();
    que.pop();
    if (cur) {
      res.push_back(to_string(cur->val));
      que.push(cur->left);
      que.push(cur->right);
    } else {
      res.push_back("NULL");
    }
  }
  while (res.back() == "NULL") {
    res.pop_back();
  }
  for (auto& str : res) {
    if (result.empty()) {
      result += str;
    } else {
      result += "," + str;
    }
  }
  std::cout << result << endl;
  return result;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  if (data.empty()) {
    return nullptr;
  }
  istringstream is(data);
  vector<string> res;
  string word;
  while (getline(is, word, ',')) {
    cout << word << " ";
    res.push_back(word);
  }

  TreeNode *root = new TreeNode(atoi(res[0].data())), *cur = nullptr;
  queue<TreeNode*> que;
  que.push(root);
  int i = 1;
  while (i < res.size() && !que.empty()) {
    cur = que.front();
    que.pop();
    if (res[i] != "NULL") {
      cur->left = new TreeNode(atoi(res[i].data()));
      que.push(cur->left);
    }
    ++i;
    if (i < res.size() && res[i] != "NULL") {
      cur->right = new TreeNode(atoi(res[i].data()));
      que.push(cur->right);
    }
    ++i;
  }
  return root;
}