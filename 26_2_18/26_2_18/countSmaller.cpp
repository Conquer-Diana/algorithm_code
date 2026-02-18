#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//计算右侧小于当前元素的个数
//给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
//
//示例 1：
//
//输入：nums = [5, 2, 6, 1]
//输出：[2, 1, 1, 0]
//解释：
//5 的右侧有 2 个更小的元素(2 和 1)
//2 的右侧仅有 1 个更小的元素(1)
//6 的右侧有 1 个更小的元素(1)
//1 的右侧有 0 个更小的元素
//
//示例 2：
//
//输入：nums = [-1]
//输出：[0]
//
//示例 3：
//
//输入：nums = [-1, -1]
//输出：[0, 0]

//与逆序对一样，同样使用分治归并的方法，化为 左+右+一左一右
//但此题需要返回目标位置后面小于的个数，所以需要用index记录原数组的下标，在归并排序的过程中，index数组也需要一个辅助数组将下标同步移动
class Solution {
public:
    int tmp1[500010], tmp2[500010];
    vector<int> countSmaller(vector<int>& nums) {

        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); i++)
            index[i] = i;

        vector<int> count(nums.size(), 0);

        mergeSort(nums, index, count, 0, nums.size() - 1);

        return count;
    }

    void mergeSort(vector<int>& nums, vector<int>& index, vector<int>& count, int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, index, count, left, mid);
        mergeSort(nums, index, count, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;

        //这些题采用归并效率高的原因是可以完美契合排序中合并两个有序数组的过程，即比较时除了比较数放进辅助数组，
        // 还可以做诸如计数等事情
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
            {
                tmp1[i] = nums[cur2];
                tmp2[i++] = index[cur2++];
            }
            else
            {
                count[index[cur1]] += right - cur2 + 1;
                tmp1[i] = nums[cur1];
                tmp2[i++] = index[cur1++];
            }
        }

        while (cur1 <= mid)
        {
            tmp1[i] = nums[cur1];
            tmp2[i++] = index[cur1++];
        }
        while (cur2 <= right)
        {
            tmp1[i] = nums[cur2];
            tmp2[i++] = index[cur2++];
        }

        for (int j = left; j <= right; j++)
        {
            nums[j] = tmp1[j - left];
            index[j] = tmp2[j - left];
        }
    }
};