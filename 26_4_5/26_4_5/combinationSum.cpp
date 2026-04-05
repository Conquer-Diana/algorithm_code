#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//组合总和
//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//
//示例 1：
//
//输入：candidates = [2, 3, 6, 7], target = 7
//输出： [[2, 2, 3], [7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。
//
//示例 2：
//
//输入 : candidates = [2, 3, 5], target = 8
//输出 : [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
//
//示例 3：
//
//输入 : candidates = [2], target = 1
//输出 : []

//解法一：决策树按照依次选candidates中的数作为第一个，第二个，第三个.....数的思路枚举来画
class Solution_1 {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //sort(candidates.begin(),candidates.end());//如果数组无序，需要把排序加上
        dfs(candidates, target, 0, 0);
        return ret;
    }
    void dfs(vector<int>& candidates, int target, int pos, int sum)//借助上一题的思路，将sum作为函数参数传递
    {
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        if (pos == candidates.size() || sum > target)
            return;

        //每次i从pos的位置开始找，即i位置前面比candidates[i]小的数就不递归，要剪枝（前面小的数枚举时已经有这种组合了）
        for (int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, target, i, sum + candidates[i]);//pos传递当前的i，而不是i+1
            path.pop_back();
        }
    }
};

//解法二：决策树按照从数组第一个元素开始分别选几个该元素的思路来画
class Solution {
    int aim;
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        aim = target;
        dfs(candidates, 0, 0);
        return ret;
    }

    void dfs(vector<int>& candidates, int pos, int sum)
    {
        //注意：这是个大坑，这个递归出口必须在下一个递归出口前面，因为当pos刚好等于candidates.size()时，但if (sum > aim || pos == candidates.size())在前面时，会先触发这个条件导致直接返回，漏解
        if (sum == aim)
        {
            ret.push_back(path);
            return;
        }

        if (sum > aim || pos == candidates.size())
            return;

        //这个思路蛮新奇的，当i * candidates[pos] + sum <= aim时就不断枚举i去乘以 candidates[pos]
        for (int i = 0; i * candidates[pos] + sum <= aim; i++)
        {
            //如果i>0，就添加到path中，i=0时，i * candidates[pos]=0，不用添加
            if (i)
                path.push_back(candidates[pos]);
            dfs(candidates, pos + 1, sum + i * candidates[pos]);//选完第一个选几个后，pos+1选第二个元素
        }

        //恢复现场，因为，没添加i=0的情况，所以这里从i=1开始
        //这里在循环外恢复现场的原因是：等pos+1位置的选几个全枚举完成之后再恢复现场，以免在上面恢复现场后还要重新添加
        for (int i = 1; i * candidates[pos] + sum <= aim; i++)
        {
            path.pop_back();
        }

    }
};

