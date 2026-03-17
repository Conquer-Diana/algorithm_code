#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//数据流中的中位数
//中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
//
//例如 arr = [2, 3, 4] 的中位数是 3 。
//例如 arr = [2, 3] 的中位数是(2 + 3) / 2 = 2.5 。
//实现 MedianFinder 类 :
//
//MedianFinder() 初始化 MedianFinder 对象。
//
//void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
//
//double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10 ^- 5 以内的答案将被接受。
//
//示例 1：
//
//输入
//["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [1], [2], [], [3], []]
//输出
//[null, null, null, 1.5, null, 2.0]
//
//解释
//MedianFinder medianFinder = new MedianFinder();
//medianFinder.addNum(1);    // arr = [1]
//medianFinder.addNum(2);    // arr = [1, 2]
//medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
//medianFinder.addNum(3);    // arr[1, 2, 3]
//medianFinder.findMedian(); // return 2.0

//解法一：来一个值就插入数组调用一次sort()，然后找数组中间的数，这样addNum()的时间复杂度为O(nlogn),find()的时间复杂度为O(1)

//解法二：来一个值就使用插入排序的方式进入数组，然后找数组中间的数，这样addNum()的时间复杂度为O(n),find()的时间复杂度为O(1)

//解法三：即下面代码的方式，使用大小堆维护中位数的方式，以中间为分界线，规定左边用大根堆left存放，右边用小根堆right存放
//如果数据个数为偶数，则左边个数m==右边个数n，最后find()时，取出左边left大根堆的堆顶与右边right小根堆的堆顶相加/2.0，即中位数
//如果数据个数为奇数，则规定左边比右边多存一个，即m==n+1,最后find()时，取出左边left大根堆的堆顶即为中位数

//处理add()中的细节问题
//当m==n时
    //如果堆为空，或者num<=left.top()，直接插入left
    //如果num>left.top()，直接插入right的话，就不满足m==n+1了，所以需要先插入right，然后将right.top()插入left (不能颠倒，因为不知道num是否小于right.top()，
    //若颠倒先将right.top()插入left的话，由于num可能小于right.top()，本来应该过去left的是num，但right.top()先过去了，导致次序乱了）

//当m>n时
    //如果num<=left.top()，直接插入left的话，就会导致m==n+2，所以需要先将num插入left，然后将left.top()插入到right
    //如果num>left.top(),直接插入right
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int m;
    int n;

public:
    MedianFinder() {

    }

    void addNum(int num) {
        m = left.size();
        n = right.size();

        if (m == n)
        {
            if (m == 0 || num <= left.top())
                left.push(num);
            else if (num > left.top())
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else if (m > n)
        {
            if (num <= left.top())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else
                right.push(num);
        }
    }

    double findMedian() {
        m = left.size();
        n = right.size();

        if (m == n)
            return (left.top() + right.top()) / 2.0;
        else
            return double(left.top());
    }
};