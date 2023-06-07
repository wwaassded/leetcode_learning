//
// Created by crasher on 2023/6/7.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==nullptr)
      return head;
    if(head->next == nullptr)
      return nullptr;
    auto ptr = head;
    for(int i=1; i<n; ++i)
      ptr = ptr->next;
    ListNode *dull = new ListNode();
    dull->next = head;
    auto it = dull;
    while(ptr->next != nullptr) {
      ptr = ptr->next;
      it = it->next;
      head = head->next;
    }
    it->next = head->next;
    return dull->next;
  }
};