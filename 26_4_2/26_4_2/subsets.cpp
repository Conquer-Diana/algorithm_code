#define _CRT_SECURE_NO_WARNINGS


#include <vector>

using namespace std;

//子集
//给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//
//示例 1：
//
//输入：nums = [1, 2, 3]
//输出： [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//
//示例 2：
//
//输入：nums = [0]
//输出： [[], [0]]

//解法一：决策树是以选不选某一元素的思想来画的
class Solution_1 {
    //全局变量
    vector<vector<int>> ret;//最终结果
    vector<int> path;//路径
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int i)//i表示元素的下标
    {
        //递归出口：当走到叶子节点即i==nums.size()时将path加入ret
        if (i == nums.size())
        {
            ret.push_back(path);
            return;
        }

        //不选
        dfs(nums, i + 1);//不选元素时，对path没有什么影响，不用恢复现场

        //选 
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();//恢复现场
    }
};

//解法二：决策树是以子集中有0，1，2。。。。个元素的思想来画的
class Solution_2 {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);//没有递归出口，只需要每次进入函数时，将当前的path添加到ret中

        //剪枝则利用从当前位置pos作为i来遍历，由于pos每次会+1.所以那些重复的子集就不会遍历了，相当于剪枝
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
};