#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//目标和
//给你一个非负整数数组 nums 和一个整数 target 。
//
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//示例 1：
//
//输入：nums = [1, 1, 1, 1, 1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//
//示例 2：
//
//输入：nums = [1], target = 1
//输出：1

//解法一：sum和count作为全局变量
class Solution_1 {
    int sum = 0;
    int count = 0;
    int ret = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target);
        return ret;
    }

    void dfs(vector<int>& nums, int target)
    {
        if (count == nums.size())
        {
            if (sum == target)
                ret++;
            return;
        }

        sum += nums[count];
        count++;
        dfs(nums, target);
        count--;
        sum -= nums[count];

        sum -= nums[count];
        count++;
        dfs(nums, target);
        count--;
        sum += nums[count];
    }
};

//解法二：sum和count作为dfs的参数传递
//由代码可以看到，像int这种变量作为函数参数传递的时候，代码就比较简洁，因为函数在递归回来的时候就自动完成恢复现场的操作了
//所以像vector<int> path这种就作为全局，像int sum这种就可以作为函数参数传递
class Solution_2 {
    int ret = 0;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums, target, 0, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int target, int count, int sum)
    {
        if (count == nums.size())
        {
            if (sum == target)
                ret++;
            return;
        }

        dfs(nums, target, count + 1, sum + nums[count]);

        dfs(nums, target, count + 1, sum - nums[count]);
    }
};