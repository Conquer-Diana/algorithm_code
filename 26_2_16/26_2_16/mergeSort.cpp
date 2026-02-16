#define _CRT_SECURE_NO_WARNINGS

#include <vector>

//归并排序 - 相当于二叉树后序遍历，左右根
//而快排相当于前序遍历，根左右
using namespace std;

class Solution {
    vector<int> tmp;//递归时为了避免每次递归都创建空间的开销，可以使用全局变量
public:
    vector<int> sortArray(vector<int>& nums) {

        tmp.resize(nums.size());//预开空间

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        //归并的关键步骤就是合并两个有序数组
        int cur1 = left, cur2 = mid + 1, i = 0;

        while (cur1 <= mid && cur2 <= right)
            tmp[i++] = nums[cur1] < nums[cur2] ? nums[cur1++] : nums[cur2++];
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        //最后需要将临时数组的数据移到原来的数组中
        for (int k = left; k <= right; k++)
            nums[k] = tmp[k - left];
    }
};