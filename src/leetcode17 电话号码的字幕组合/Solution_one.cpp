//
// Created by crasher on 2023/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string fakeMap[] = {"","","abc","def","ghi","ikl","mno","pqrs","tuv","wxyz"};
    int size = digits.size();
    if(size == 0)
      return {};
    vector<string> res;
    string ans;
    for(const auto &item : fakeMap[digits[0]-'0']) {
      ans.push_back(item);
      this->func(res,ans,size,fakeMap,1,digits);
      ans.pop_back();
    }
    return res;
  }

  void func(vector<string> &res,string &ans,const int &size,string fakeMap[],int number,const string &digits) {
    int len = ans.size();
    if(len == size)
      res.emplace_back(ans);
    else {
      for(const auto &item : fakeMap[digits[number]-'0']) {
        ans.push_back(item);
        this->func(res,ans,size,fakeMap,number+1,digits);
        ans.pop_back();
      }
    }
  }
};

