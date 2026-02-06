#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//和可被k整除的子数组
//给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。
//
//子数组 是数组中 连续 的部分。
//
//示例 1：
//
//输入：nums = [4, 5, 0, -2, -3, 1], k = 5
//输出：7
//解释：
//有 7 个子数组满足其元素之和可被 k = 5 整除：
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//
//示例 2:
//
//输入: nums = [5], k = 9
//输出 : 0

//知识补充：
//同余定理：
//(a-b)/p=k......0 -> a%p=b%p,(a+p*k)%p=a

//c++中 负数%正数修正 -> num(负数）% k + k
//为了正负数统一 -> (num % k + k) % k

//假设[0~i] 要找到i前面某一个子数组[a,i]之和x被k整除，即(sum-x)%k=0 -> sum%k=x%k
//即找到[0,i-1]区间内有多少个前缀和%k=sum%k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;//记录余数出现的次数
        hash[0] = 1;//0的余数

        int sum = 0, ret = 0;

        for (auto x : nums)
        {
            sum += x;
            if (hash.count((sum % k + k) % k))
                ret += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }

        return ret;
    }
};