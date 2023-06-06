//
// Created by crasher on 2023/6/6.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int size = nums.size();
    unordered_map<int,int> foo;
    for(int i=0; i<size; ++i) {
      auto it = foo.find(target - nums[i]);
      if(it != foo.end()) {
        res.emplace_back(it->second);
        res.emplace_back(i);
        return res;
      }
      foo.emplace(nums[i],i);
    }
    return res;
  }
};
