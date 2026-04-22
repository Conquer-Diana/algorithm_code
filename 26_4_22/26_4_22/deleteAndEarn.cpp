#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//给你一个整数数组 nums ，你可以对它进行一些操作。
//
//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
//
//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//
//示例 1：
//输入：nums = [3, 4, 2]
//输出：6
//解释：
//你可以执行下列步骤：
//- 删除 4 获得 4 个点数，因此 3 也被删除。nums = [2]。
//- 之后，删除 2 获得 2 个点数。nums = []。
//总共获得 6 个点数。
//
//示例 2：
//输入：nums = [2, 2, 3, 3, 3, 4]
//输出：9
//解释：
//你可以执行下列步骤：
//- 删除 3 获得 3 个点数。所有的 2 和 4 也被删除。nums = [3, 3]。
//- 之后，再次删除 3 获得 3 个点数。nums = [3]。
//- 再次删除 3 获得 3 个点数。nums = []。
//总共获得 9 个点数。

//这道题要从中学会把新题往曾经写过的题上面靠
//一眼看上去，这题很像《打家劫舍》，但由于数组内的数很可能不是相差一的，所以需要对数组进行一个预处理
//预处理就是新开一个数组，其中以原始数组的元素作为下标，存储原始数组中对应元素出现的次数*该元素的值，没有出现的数字为0
//这样对新数组进行一次《打家劫舍》即可
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001);

        for (int num : nums)
            arr[num] += num;

        int sz = arr.size();
        vector<int> fx(sz), gx(sz);

        fx[0] = arr[0];

        for (int i = 1; i < sz; i++)
        {
            fx[i] = gx[i - 1] + arr[i];
            gx[i] = max(fx[i - 1], gx[i - 1]);
        }

        return max(fx[sz - 1], gx[sz - 1]);
    }
};