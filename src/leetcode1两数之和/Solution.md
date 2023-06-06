# 哈希表的简单应用

~~所提供数组是无序的排序之后位置也发生了变化~~

```
auto it = foo.find(target - nums[i]);
      if(it != foo.end()) {
        res.emplace_back(it->second);
        res.emplace_back(i);
        return res;
      }
      foo.emplace(nums[i],i);
```

使用哈希表查找是否有我们想要的值，target-nums[i]就是我们的目标值

**一定注意插入于查找的顺序问题**

使用了unordered_map时间复杂度应该是 O(nlogn)
