#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//快速排序

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned int)time(nullptr));
        int n = nums.size();

        qsort(nums, 0, n - 1);

        return nums;
    }

    void qsort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        //用随机数选取key值
        int r = rand();
        int key = nums[r % (right - left + 1) + left];

        int begin = left - 1, end = right + 1, i = left;

        //套用“颜色划分”的做法三路划分，可以防止数组中重复数字太多造成的时间复杂度退化，因为递归只递归两边，中间的数不递归
        while (i < end)
        {
            if (nums[i] < key)
                swap(nums[++begin], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[--end], nums[i]);
        }

        qsort(nums, left, begin);
        qsort(nums, end, right);
    }
};