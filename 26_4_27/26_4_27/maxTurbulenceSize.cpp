#define _CRT_SECURE_NO_WARNINGS


#include <vector>

using namespace std;

//最长湍流子数组
//给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。
//
//如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。
//
//更正式地来说，当 arr 的子数组 A[i], A[i + 1], ..., A[j] 满足仅满足下列条件时，我们称其为湍流子数组：
//
//若 i <= k < j ：
//	当 k 为奇数时， A[k] > A[k + 1]，且
//	当 k 为偶数时，A[k] < A[k + 1]；
//	或 若 i <= k < j ：
//	当 k 为偶数时，A[k] > A[k + 1] ，且
//	当 k 为奇数时， A[k] < A[k + 1]。
//
//示例 1：
//输入：arr = [9, 4, 2, 10, 7, 8, 8, 1, 9]
//输出：5
//解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
//
//示例 2：
//输入：arr = [4, 8, 12, 16]
//输出：2
//
//示例 3：
//输入：arr = [100]
//输出：1

//湍流数组形象化理解就是呈现“锯齿波浪”型的数组，即“一上一下”
class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        //fx[i]表示以i位置为结尾，最后呈现“上升”趋势的最大湍流子数组长度
        //gx[i]表示以i位置为结尾，最后呈现“下降”趋势的最大湍流子数组长度
        vector<int> fx(n, 1), gx(n, 1);
        //因为就算是1个数，题目所叙述的湍流数组长度也是1，所以将两个dp表都初始化为1

        int fmax = 1, gmax = 1;//最差情况长度也是1
        for (int i = 1; i < n; i++)
        {
            //当nums[i] > nums[i - 1]时，呈现”上升“趋势，这时候fx[i]等于以i-1位置为结尾，呈”下降“趋势的长度+1，即gx[i-1]+1，gx[i]由于最后是上升的，所以只能nums[i]单干，长度等于1（这就体现出将两个dp表初始化为1的好处，就不用单独处理gx了）
            if (nums[i] > nums[i - 1])
                fx[i] = gx[i - 1] + 1;
            //当nums[i] < nums[i - 1]时，呈现”下降“趋势，这时候gx[i]等于以i-1位置为结尾，呈”上升“趋势的长度+1，即fx[i-1]+1，fx[i]由于最后是下降的，所以只能nums[i]单干，长度等于1（这就体现出将两个dp表初始化为1的好处，就不用单独处理fx了）
            else if (nums[i] < nums[i - 1])
                gx[i] = fx[i - 1] + 1;
            //当nums[i] == nums[i - 1]时，只能nums[i]单干，等于1(再次体现初始化为1的好处）

            fmax = max(fmax, fx[i]);
            gmax = max(gmax, gx[i]);
        }

        //最后答案是无论最后是上升还是下降，两个dp表中的最大值
        return max(fmax, gmax);
    }
};