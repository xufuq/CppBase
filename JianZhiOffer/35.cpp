#include <unordered_map>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

Node* copyRandomList(Node* head) {
  unordered_map<Node*, Node*> mp;
  Node* new_head = nullptr;
  if (head) {
    new_head = new Node(head->val);
    mp[head] = new_head;
  } else {
    return new_head;
  }
  Node* cur = new_head;
  Node* old_cur = head;
  while (old_cur->next) {
    cur->next = new Node(old_cur->next->val);
    old_cur = old_cur->next;
    cur = cur->next;
    mp[old_cur] = cur;
  }
  cur = new_head;
  old_cur = head;
  while (cur) {
    cur->random = mp[old_cur->random];
    cur = cur->next;
    old_cur = old_cur->next;
  }
  return new_head;
}