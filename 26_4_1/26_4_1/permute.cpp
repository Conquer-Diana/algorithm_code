#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//全排列
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出： [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
//示例 2：
//
//输入：nums = [0, 1]
//输出： [[0, 1], [1, 0]]
//示例 3：
//
//输入：nums = [1]
//输出： [[1]]

//1.画出决策树，越详细越好
//2.设计代码
//  全局变量：ret-最终结果，path-记录路径，check-实现剪枝（存的是nums中元素的下标）
//  dfs只需关心每一个结点在干什么
//  细节问题：回溯：恢复现场——干掉path最后一个元素，将check[i]重新置为false
//  剪枝 —— 由check每次检查该下标的值是否为true，为true则剪掉
class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            //可以选择在这里恢复现场，但dfs可能不止在这里返回，也可能在下面返回，所以统一在下面恢复现场，即在结点回溯回来时再统一恢复
            return;
        }

        for (int i = 0; i < nums.size(); i++)
            if (check[i] == false)
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                //回溯 —— 恢复现场
                path.pop_back();
                check[i] = false;
            }
    }
};