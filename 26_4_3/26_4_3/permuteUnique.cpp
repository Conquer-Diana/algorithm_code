#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//全排列_2
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//
//示例 1：
//
//输入：nums = [1, 1, 2]
//输出：
//[[1, 1, 2],
//[1, 2, 1],
//[2, 1, 1]]
//示例 2：
//
//输入：nums = [1, 2, 3]
//输出： [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

//这道题与《全排列》相比，就是多了重复的元素，如何处理重复排列的剪枝问题是这道题的关键
//利用check数组和与前一个元素是否相等作为剪枝的依据
//所以需要先排序数组，将可能相等的元素排在一起
//如果check[i]已经访问过，或者该元素与前一个元素相等并且前一个元素在check数组中为false就剪枝（与前一个元素相等有两种情况：1.check[i-1]=true，说明前一个元素被选了，那么这个与他相等的元素就还可以选（位于不同层次）
//2.check[i-1]=false，说明前一个相等元素可能递归返回，check被置为了false，而与他相等的这个元素再递归的话得到的就是重复值，所以将此位置剪枝）

//解法一：只考虑如何跳过不合法的分支
class Solution_1 {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9];
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            //考虑不合法的分支
            if (check[i] || i > 0 && nums[i] == nums[i - 1] && check[i - 1] == false)//i>0 是为了防止nums[i-1]越界
                continue;

            path.push_back(nums[i]);
            check[i] = true;
            dfs(nums);
            path.pop_back();
            check[i] = false;
        }
    }
};

//解法二：只考虑如何遍历那些合法的分支，两种解法判断条件刚好反过来
class Solution_2 {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[9];
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            //考虑合法的分支
            //check数组必须没有被访问过并且要么i==0，要么i！=0，nums[i]!=nums[i-1]，要么i！=0,nums[i]==nums[i-1],但check[i-1]=true
            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
            {
                path.push_back(nums[i]);
                check[i] = true;
                dfs(nums);
                path.pop_back();
                check[i] = false;
            }
        }
    }
};