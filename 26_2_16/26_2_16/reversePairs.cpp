#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//交易逆序对的总数
//在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数。
//
//示例 1：
//
//输入：record = [9, 7, 5, 4, 6]
//输出：8
//解释：交易中的逆序对为(9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。

//使用分治归并的思想，将其转化为左区间逆序对个数+右区间逆序对个数+一左一右的逆序对个数
//步骤为：求 1.左区间个数，左排序  2.右区间个数，右排序  3.一左一右个数 排序
// 1 和 2 交给递归解决
//重点就在第3步，有两种策略： 1.升序排列，cur1和cur2逐渐变大，移动cur1怎么时候大于cur2，大于的时候可以得出cur1后面的所有组合
class Solution_1 {
    int tmp[50010];
public:
    int reversePairs(vector<int>& record) {
        return mergeSort(record, 0, record.size() - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int ret = 0;

        ret += mergeSort(nums, left, mid);
        ret += mergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;

        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
                tmp[i++] = nums[cur1++];
            else
            {
                ret += mid - cur1 + 1;
                tmp[i++] = nums[cur2++];
            }
        }
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        for (int i = left; i <= right; i++)
            nums[i] = tmp[i - left];

        return ret;
    }
};

//降序排序 cur1和cur2逐渐变小，移动cur2看他什么时候小于cur1，小于时即可得出cur2后面所有组合
class Solution_2 {
    int tmp[50010];
public:
    int reversePairs(vector<int>& record) {
        return mergeSort(record, 0, record.size() - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int ret = 0;

        ret += mergeSort(nums, left, mid);
        ret += mergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;

        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
                tmp[i++] = nums[cur2++];
            else
            {
                ret += right - cur2 + 1;
                tmp[i++] = nums[cur1++];
            }
        }
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        for (int i = left; i <= right; i++)
            nums[i] = tmp[i - left];

        return ret;
    }
};