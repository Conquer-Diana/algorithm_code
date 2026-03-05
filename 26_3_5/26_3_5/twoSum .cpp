#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map>
#include <vector>

using namespace std;

//两数之和
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//
//你可以按任意顺序返回答案。
//
//示例 1：
//
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//
//示例 2：
//
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
//
//示例 3：
//
//输入：nums = [3, 3], target = 6
//输出：[0, 1]

//哈希表版，根据暴力枚举固定一个数向前找的方法优化而来
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        //遍历数组，如果没有在hash表中，则加入，如果检索到hash表中有值为target - nums[i]的数，则直接返回下标
        //整体是一个向前找的过程
        //若根据暴力向后找来优化的话，则需要判断是否是自己本身+本身=target
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(target - nums[i]))
                return { i,hash[target - nums[i]] };

            hash[nums[i]] = i;
        }
        return {};
    }
};