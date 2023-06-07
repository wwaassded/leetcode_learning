//
// Created by crasher on 2023/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int size = height.size();
    int res = 0;
    int left = 0;
    int right = size-1;
    while(left < right) {
      int number = min(height[left],height[right]) * (right-left);
      res = max(res,number);
      if(height[left] <= height[right])
        ++left;
      else
        --right;
    }
    return res;
  }
};