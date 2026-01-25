#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

//复写零
//给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
//
//注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
//
//示例 1：
//
//输入：arr = [1, 0, 2, 3, 0, 4, 5, 0]
//输出：[1, 0, 0, 2, 3, 0, 0, 4]
//解释：调用函数后，输入的数组将被修改为：[1, 0, 0, 2, 3, 0, 0, 4]
// 
//示例 2：
//
//输入：arr = [1, 2, 3]
//输出：[1, 2, 3]
//解释：调用函数后，输入的数组将被修改为：[1, 2, 3]

//双指针，先根据“异地”操作，然后优化为“就地”的双指针操作

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int dest = -1;
        int cur = 0;

        //1.先找到复写后的最后一个数字
        while (cur < arr.size())
        {
            if (arr[cur] != 0)
                ++dest;
            else
                dest += 2;

            if (dest >= arr.size() - 1)
                break;

            ++cur;//此时cur的位置就是复写后最后一个数字
        }

        //2.解决越界情况，越界了，此时将最后一个数字赋值为0，将cur--，dest-2，从此位置开始从后往前复写
        if (dest == arr.size())
        {
            arr[arr.size() - 1] = 0;
            --cur;
            dest -= 2;
        }

        //3.从后往前进行复写
        while (cur >= 0 && dest >= 0)
        {
            //非0，dest走一步，赋值为arr[cur]
            if (arr[cur] != 0)
            {
                arr[dest--] = arr[cur--];
            }
            //为0，dest走两步，且赋值为0
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};