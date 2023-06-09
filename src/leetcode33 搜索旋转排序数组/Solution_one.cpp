//
// Created by crasher on 2023/6/9.
//
#include <vector>

using namespace std;
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] == target) return mid;
      if (nums[left] <= nums[mid]) {
        // left 到 mid 是顺序区间
        (target >= nums[left] && target < nums[mid]) ? right = mid - 1 : left = mid + 1;
      }
      else {
        // mid 到 right 是顺序区间
        (target > nums[mid] && target <= nums[right]) ? left = mid + 1 : right = mid - 1;
      }
    }
    return -1;
  }
};