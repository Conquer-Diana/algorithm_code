#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//盛水最多的容器
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
//
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//
//返回容器可以储存的最大水量。
//
//说明：你不能倾斜容器。
//
//输入：[1, 8, 6, 2, 5, 4, 8, 3, 7]
//输出：49
//解释：图中垂直线代表输入数组[1, 8, 6, 2, 5, 4, 8, 3, 7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。


//双指针，关键在发现单调性规律，如[6,2,5,4]，先选最两边的6和4，得4*3=12，以较小的4为基准向内计算，发现宽度始终在变短，长度变短或者不变，所以4就可以排除掉，以此类推
class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int left = 0;
		int right = height.size() - 1;
		int maxv = 0;

		while (left <= right)
		{
			int minht = min(height[left], height[right]);
			int v = minht * (right - left);

			maxv = max(maxv, v);

			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return maxv;
	}
};