#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map>
#include <vector>

using namespace std;

//存在重复元素_2
//给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//
//示例 1：
//
//输入：nums = [1, 2, 3, 1], k = 3
//输出：true
//
//示例 2：
//
//输入：nums = [1, 0, 1, 1], k = 1
//输出：true
//
//示例 3：
//
//输入：nums = [1, 2, 3, 1, 2, 3], k = 2
//输出：false

//哈希表，存元素和下标，满足条件直接返回，不满足插入
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(nums[i]) && abs(hash[nums[i]] - i) <= k)
                return true;
            hash[nums[i]] = i;//这里会覆盖前面相同的数的下标，但也满足要求，因为题目要求的是越近的，如果前面的abs(i - j)>k了，后面就算再找到相同的，不覆盖的话，还是不满足要求，所以用近的覆盖远的
        }
        return false;
    }
};