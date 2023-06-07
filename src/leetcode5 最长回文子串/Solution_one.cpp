//
// Created by crasher on 2023/6/6.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int size = s.size();
    vector<vector<bool>> dp(size,vector<bool>(size,false));
    for(int i=0; i<size; ++i)
      dp[i][i] = true;
    int maxLen = 1;
    int left = 0;
    for(int len=2; len<=size; ++len)
      for(int i=0; i+len-1<size; ++i) {
        int j = i+len-1;
        if(len == 2) {
          if(s[i] == s[i+1])
            dp[i][j] = true;
          else
            dp[i][j] = false;
        }
        else {
          if(s[i] == s[j]) {
            if(dp[i+1][j-1])
              dp[i][j] = true;
            else
              dp[i][j] = false;
          }
          else
            dp[i][j] = false;
        }
        if(dp[i][j] && len > maxLen) {
          maxLen = len;
          left = i;
        }
      }
    return s.substr(left,maxLen);
  }
};
