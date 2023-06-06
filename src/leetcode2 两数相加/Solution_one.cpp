//
// Created by crasher on 2023/6/6.
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto dull = new ListNode();
    ListNode *tail = dull;
    int sum = 0;
    int car = 0;
    while(l1!=nullptr || l2!=nullptr) {
      if(l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if(l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      sum += car;
      car = sum / 10;
      sum = sum % 10;
      tail->next = new ListNode(sum);
      tail = tail->next;
      sum = 0;
    }
    if(car != 0)
      tail->next = new ListNode(car);
    return dull -> next;
  }
};