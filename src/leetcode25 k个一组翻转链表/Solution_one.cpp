//
// Created by crasher on 2023/6/8.
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    int number = 0;
    auto dummy = new ListNode();
    dummy->next = head;
    while(head != nullptr) {
      ++number;
      head = head->next;
    }
    auto pre = dummy;
    auto cur = pre->next;
    head = dummy;
    while (number >= k) {
      number -= k;
      for(int i=1; i<=k; ++i) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
      }
      head->next->next = cur;
      auto it = head->next;
      head->next = pre;
      pre = it;
      head = it;
    }
    return dummy->next;
  }
};