#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <vector>

using namespace std;

//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
//
//示例：
//
//输入： arr = [1, 3, 5, 7, 2, 4, 6, 8], k = 4
//输出：[1, 2, 3, 4]

//用快速选择算法，可以解决第k大，第k小，前k大，前k小
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand(time(nullptr));
        int n = arr.size();

        qsort(arr, 0, n - 1, k);

        //最后返回经过调整的前k个最小的
        return { arr.begin(),arr.begin() + k };
    }

    void qsort(vector<int>& arr, int l, int r, int k)
    {
        if (l >= r)
            return;

        //依旧是套路解法，随机选择k，将数组分为三段
        int random = rand();
        int key = arr[r % (r - l + 1) + l];

        int left = l - 1, right = r + 1, i = l;

        while (i < right)
        {
            if (arr[i] < key)
                swap(arr[++left], arr[i++]);
            else if (arr[i] == key)
                i++;
            else
                swap(arr[--right], arr[i]);
        }

        //找前k小，则从前面找起
        int a = left - l + 1;
        int b = right - left - 1;

        //若第一个区间>k，则答案就在这个区间内，继续递归
        if (a >= k)
            qsort(arr, l, left, k);
        //若前两个区间加起来大于k，则答案包含第一个区间，第二个区间都是相等的数，直接返回
        else if (a + b >= k)
            return;
        //若答案在第三个区间，则递归第三个区间即可
        else
            qsort(arr, right, r, k - a - b);

    }
};