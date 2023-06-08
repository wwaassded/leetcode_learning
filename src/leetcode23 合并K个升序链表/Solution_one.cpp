//
// Created by crasher on 2023/6/8.
//
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  struct cmp {
    bool operator()(ListNode *a,ListNode *b) {
      return a->val < b->val;
    }
  };

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,cmp> ans;
    for(const auto &item : lists)
      if(item != nullptr)
        ans.emplace(item);
    auto dull = new ListNode(0);
    auto tail = dull;
    while(!ans.empty()) {
      auto it = ans.top();
      ans.pop();
      if(it->next != nullptr)
        ans.emplace(it->next);
      it->next = nullptr;
      tail->next = it;
      tail = tail->next;
    }
    return dull->next;
  }
};