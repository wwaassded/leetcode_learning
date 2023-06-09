//
// Created by crasher on 2023/6/9.
//
#include <deque>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
  int longestValidParentheses(string s) {
    deque<int> ans;
    int size = s.size();
    vector<int> validSequen(size,0);
    for(int i=0; i<size; ++i) {
      if(s[i] == '(')
        ans.emplace_back(i);
      else if(ans.empty()) {
        validSequen[i] = 1;
      }
      else
        ans.pop_back();
    }
    while(!ans.empty()) {
      auto it = ans.back();
      ans.pop_back();
      validSequen[it] = 1;
    }
    int max_Res = 0;
    int number = 0;
    for(int i=0; i<size; ++i) {
      if(validSequen[i] == 0)
        ++number;
      else {
        max_Res = max(max_Res,number);
        number = 0;
      }
    }
    return max(max_Res,number);
  }
};
int main() {
  Solution().longestValidParentheses("(()");
  return 0;
}
//")()())"