#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//编写一个算法来判断一个数 n 是不是快乐数。
//
//「快乐数」 定义为：
//
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为 1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

//示例 1：
//
//输入：n = 19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1

//示例 2：
//
//输入：n = 2
//输出：false

//双指针，此题与环形链表相似，最终都会形成一个环，快慢指针最终相遇的数为1为快乐数，否则不是快乐数
class Solution
{
public:
	int bitSum(int n)
	{
		int sum = 0;
		while (n)
		{
			int t = n % 10;
			sum += t * t;
			n /= 10;
		}
		return sum;
	}

	bool isHappy(int n)
	{
		int slow = n;
		int fast = bitSum(n);

		while (slow != fast)
		{
			//满指针走一步，快指针走两步
			slow = bitSum(slow);
			fast = bitSum(bitSum(fast));
		}

		return slow == 1;
	}
};