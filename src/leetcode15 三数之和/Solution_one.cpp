//
// Created by crasher on 2023/6/7.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> res;
    for(int i=0; i+2<size; ++i) {
      if(i!=0 && nums[i]==nums[i-1])
        continue ;
      if(nums[i]+nums[i+1]+nums[i+2] > 0)
        continue ;
      if(nums[i]+nums[size-1]+nums[size-2] < 0)
        continue ;
      int target = -nums[i];
      int left = i+1;
      int right = size-1;
      while(left < right) {
        int number = nums[left] + nums[right];
        if(number == target) {
          vector<int> tmp {nums[i],nums[left],nums[right]};
          res.emplace_back(tmp);
          while(nums[left]==tmp[1] && left<size-1)
            ++left;
        }
        else {
          if(number < target)
            ++left;
          else
            --right;
        }
      }
    }
    return res;
  }
};
