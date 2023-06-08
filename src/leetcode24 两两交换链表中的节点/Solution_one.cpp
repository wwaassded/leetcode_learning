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
  ListNode* swapPairs(ListNode* head) {
    if(head==nullptr || head->next==nullptr)
      return head;
    else {
      auto dull = new ListNode(0);
      dull->next = head;
      auto mid = head;
      auto las = head->next;
      auto pre = dull;
      while(mid->next!=nullptr) {
        mid->next = las->next;
        las->next = mid;
        pre->next = las;
        pre = mid;
        mid = mid->next;
        if(mid != nullptr)
          las = mid->next;
        else
          break ;
      }
      return dull->next;
    }
  }
};
