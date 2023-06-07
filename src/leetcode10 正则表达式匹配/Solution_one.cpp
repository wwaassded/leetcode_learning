//
// Created by crasher on 2023/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int rol = s.size();
    int col = p.size();
    vector<vector<bool>> dp(rol+1,vector<bool>(col+1,false));
    dp[0][0] = true;
    for(int i=1; i<=col; ++i) {
      if(p[i-1] == '*') {
        if(dp[0][i-2])
          dp[0][i] = true;
        else
          dp[0][i] = false;
      }
      else
        dp[0][i] = false;
    }
    for(int i=1; i<=rol; ++i)
      for(int j=1; j<=col; ++j) {
          if(p[j-1]!='*' && p[j-1]!='.') {
            if(p[j-1] == s[i-1]) {
              if(dp[i-1][j-1])
                dp[i][j] = true;
              else
                dp[i][j] = false;
            }
            else
              dp[i][j] = false;
          }
          else if(p[j-1] == '.') {
            if(dp[i-1][j-1])
              dp[i][j] = true;
            else
              dp[i][j] = false;
          }
          else {
            if(dp[i][j-1] || dp[i][j-2])
              dp[i][j] = true;
            else {
              if(dp[i-1][j] && (p[j-2]=='.' || p[j-2]==s[i-1]))
                dp[i][j] = true;
              else
                dp[i][j] = false;
            }
          }
      }
    return dp[rol][col];
  }
};
