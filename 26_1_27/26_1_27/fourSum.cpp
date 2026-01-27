#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//四数之和
//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//
//0 <= a, b, c, d < n
//    a、b、c 和 d 互不相同
//    nums[a] + nums[b] + nums[c] + nums[d] == target
//    你可以按 任意顺序 返回答案 。
//
//    示例 1：
//
//    输入：nums = [1, 0, -1, 0, -2, 2], target = 0
//    输出： [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

//    示例 2：
//
//    输入：nums = [2, 2, 2, 2, 2], target = 8
//    输出： [[2, 2, 2, 2]]

//与三数之和类似，四数之和只不过多锁定一个数，锁定两个数，然后两数之和=target-a-b，然后注意去重和越界检查
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; i++)
        {
            while (i >= 1 && i < n - 3 && nums[i] == nums[i - 1])
            {
                i++;
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                while (j >= 2 && j < n - 2 && nums[j] == nums[j - 1] && i + 1 != j)
                {
                    j++;
                }

                int left = j + 1;
                int right = n - 1;
                long long temp = (long long)target - nums[i] - nums[j];

                while (left < right)
                {
                    int sum = nums[left] + nums[right];

                    if (sum > temp)
                        right--;
                    else if (sum < temp)
                        left++;
                    else
                    {
                        ret.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        while (left < right && nums[++left] == nums[left - 1]) {}
                        while (left < right && nums[--right] == nums[right + 1]) {}
                    }
                }
            }

        }

        return ret;
    }
};