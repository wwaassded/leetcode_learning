//
// Created by crasher on 2023/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int size = s.size();
    if(size < 2)
      return s;
    int maxLen = 0;
    pair<int,int> res;
    for(int i=0;i<size-1; ++i) {
      auto odd = expand(s,i,i);
      auto even = expand(s,i,i+1);
      odd = odd.second > even.second ? odd: even;
      if(odd.second > maxLen) {
        maxLen = odd.second;
        res = odd;
      }
    }
    return s.substr(res.first,res.second);
  }

  pair<int,int> expand(const string &str,int i,int j) {
    int size = str.size();
    int left = i,right = j;
    while(left>=0 && right<size) {
      if(str[left] == str[right]) {
        ++left;
        --right;
      }
      else
        break ;
    }
    return {left+1,right-left-1};
  }
};