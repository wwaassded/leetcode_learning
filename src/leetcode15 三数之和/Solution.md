# 经典双指针的应用题

`nums[i] + nums[j] + nums[k] == 0`要求看似十分的复杂，但是我们可以化简得到我们想要的表达式

`nums[j] + nums[k] == -nums[i]`，是不是有思路了呢？

**本体与leetcod 11 十分地相似**

我们遍历所有的nums[i] 在nums[i]的右侧去寻找符合规定的两个数，

*nums需要事先排序*

```
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
````

以便于我们的查找工作

`

```
if(i!=0 && nums[i]==nums[i-1])
        continue ;
/*

*/```while(nums[left]==tmp[1] && left<size-1) ++left;` 
```

用于防止重复查找


`

```
if(nums[i]+nums[i+1]+nums[i+2] > 0)
        continue ;
      if(nums[i]+nums[size-1]+nums[size-2] < 0)
        continue ;
````

使用最大三元组和，与最小三元组和剪枝
