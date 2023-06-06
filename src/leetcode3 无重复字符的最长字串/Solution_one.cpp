//
// Created by crasher on 2023/6/6.
//
#include <bits//stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> foo;
    int max_Res = 0;
    int size = s.size();
    int len = 0;
    for(int i=0; i<size; ++i) {
      ++foo[s[i]];
      if(foo[s[i]] != 1) {
        max_Res = max(max_Res,len);
        ++len;
        while(foo[s[i]] != 1) {
          --len;
          --foo[s[i-len]];
        }
      }
      else
        ++len;
    }
    return max(max_Res,len);
  }
};