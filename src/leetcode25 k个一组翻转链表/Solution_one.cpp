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
    if(head==nullptr || head->next==nullptr)
      return head;
    else {
      int number = 0;
      auto dull = new ListNode(0);
      dull->next = head;
      while(head!=nullptr) {
        head = head->next;
        ++number;
      }
      head = dull->next;
      auto pre = dull;
      auto cur = head;
      head = dull;
      while(number >= k) {
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
        head = it;
        pre = head;
      }
      return dull->next;
    }
  }
};