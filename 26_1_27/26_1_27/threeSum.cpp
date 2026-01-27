#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//三数之和
//给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//示例 1：
//输入：nums = [-1, 0, 1, 2, -1, -4]
//输出： [[-1, -1, 2], [-1, 0, 1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是[-1, 0, 1] 和[-1, -1, 2] 。
//注意，输出的顺序和三元组的顺序并不重要。

//示例 2：
//输入：nums = [0, 1, 1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。

//示例 3：
//输入：nums = [0, 0, 0]
//输出： [[0, 0, 0]]
//	解释：唯一可能的三元组和为 0 。

//先排序
//先锁定第一个数，再利用双指针在后面的区间里找到和为锁定数相反数的组合
//找到一组之后不能停下来，区间继续收缩，但要去重，就前一个数与当前数相同则跳过，但要注意越界问题
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());

		int n = nums.size();
		for (int i = 0; i < n - 2; i++)
		{
			if (nums[i] > 0)//小优化，当找到为正数时，后面的加起来不可能为0，则跳出
				break;

			while (i >= 1 && i < n - 2 && nums[i] == nums[i - 1])//前面的锁定数遇到相同的也需要跳过，且注意越界
			{
				i++;
			}

			int target = -nums[i];
			int left = i + 1;
			int right = n - 1;

			while (left < right)
			{
				int sum = nums[left] + nums[right];
				if (sum > target)
					right--;
				else if (sum < target)
					left++;
				else
				{
					ret.push_back({ nums[i],nums[left],nums[right] });
					//左右指针去重，注意越界
					while (left < right && nums[++left] == nums[left - 1]) {}
					while (left < right && nums[--right] == nums[right + 1]){}
				}

			}
		}

		return ret;
	}
};