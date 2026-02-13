#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//颜色分类
//给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
//必须在不使用库内置的 sort 函数的情况下解决这个问题。
//
//示例 1：
//
//输入：nums = [2, 0, 2, 1, 1, 0]
//输出：[0, 0, 1, 1, 2, 2]
//
//示例 2：
//
//输入：nums = [2, 0, 1]
//输出：[0, 1, 2]

//三路划分的基本思想，运用三指针将数组划分为三个区域
//[0,left] 全都是0
//[left+1,i-1] 全都是1
//[i,right-1] 待扫描的元素
//[right,n-1]全都是2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0, left = -1, right = n;

        while (i < right)//不是i<n,当i=right时停下
        {
            if (nums[i] == 0)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == 2)
                swap(nums[--right], nums[i]);//为2时，交换后i不能不能动，因为换过来如果是0，还需要再次交换
            else
                i++;
        }
    }
};
