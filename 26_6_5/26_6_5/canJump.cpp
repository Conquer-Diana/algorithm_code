#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//跳跃游戏
//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
//
//示例 1：
//输入：nums = [2, 3, 1, 1, 4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
//
//示例 2：
//输入：nums = [3, 2, 1, 0, 4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。

//就是《跳跃游戏_2》换一个问法
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;

        while (left <= right)//《跳跃游戏_2》是一定能到达n-1，这个不一定，所以用此循环条件来判断是否跳的到n-1位置
        {
            if (right >= n - 1)
                return true;

            int tmp = 0;
            while (left <= right)
                tmp = max(tmp, left + nums[left++]);
            right = tmp;
        }
        return false;
    }
};