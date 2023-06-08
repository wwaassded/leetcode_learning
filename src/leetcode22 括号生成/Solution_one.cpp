//
// Created by crasher on 2023/6/8.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string ans;
    ans.push_back('(');
    this->func(res,ans,n-1,1);
    return res;
  }
  void func(vector<string> &res,string &ans,int left_number,int right_number) {
    if(left_number==0 && right_number==0)
      res.emplace_back(ans);
    else {
      if(left_number != 0) {
        ans.push_back('(');
        this->func(res,ans,left_number-1,right_number+1);
        ans.pop_back();
      }
      if(right_number != 0) {
        ans.push_back(')');
        this->func(res,ans,left_number,right_number-1);
        ans.pop_back();
      }
    }
  }
};