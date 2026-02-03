#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//山脉数组的峰顶索引
//符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：
//
//arr.length >= 3
//存在 i（0 < i < arr.length - 1）使得：
//    arr[0] < arr[1] < ... arr[i - 1] < arr[i]
//    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i ，
//即山峰顶部。

//示例 1：
//
//输入：arr = [0, 1, 0]
//输出：1
//示例 2：
//
//输入：arr = [0, 2, 1, 0]
//输出：1
//示例 3：
//
//输入：arr = [0, 10, 5, 2]
//输出：1

//二分进阶模板使用，找到二段性
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;

        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;

            if (arr[mid] > arr[mid - 1])
                left = mid;
            else if (arr[mid] < arr[mid - 1])
                right = mid - 1;
        }

        return left;
    }
};

//另一种写法
class Solution_other {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1;
        int right = arr.size() - 2;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid + 1] > arr[mid])
                left = mid + 1;
            else if (arr[mid + 1] < arr[mid])
                right = mid;
        }

        return left;
    }
};