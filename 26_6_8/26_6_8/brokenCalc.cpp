#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//坏了的计算器
//在显示着数字 startValue 的坏计算器上，我们可以执行以下两种操作：
//
//双倍（Double）：将显示屏上的数字乘 2；
//递减（Decrement）：将显示屏上的数字减 1 。
//给定两个整数 startValue 和 target 。返回显示数字 target 所需的最小操作数。
//
//示例 1：
//输入：startValue = 2, target = 3
//输出：2
//解释：先进行双倍运算，然后再进行递减运算{ 2 -> 4 -> 3 }.
//
//示例 2：
//输入：startValue = 5, target = 8
//输出：2
//解释：先递减，再双倍{ 5 -> 4 -> 8 }.
//
//示例 3：
//输入：startValue = 3, target = 10
//输出：3
//解释：先双倍，然后递减，再双倍{ 3 -> 6 -> 5 -> 10 }.

//思路一：正向推导：startValue = 5, target = 8，贪心去想，一个数想迅速增大，方法一定是乘2，但此时5*2==10，要想变成8，需要减两次2，所以是3次操作，但如果是5先-1，再2倍，就能到8，这时才2次操作，但对于一个数乘2或是减1与否
//需要很复杂的证明
//思路二：正难则反，反向推导，从target来推导startValue，此时分为两种情况，1.target<=startValue,此时操作就只能选择+1,所以此时用startValue-target即可
//2.target>startValue，那么操作就是/2和+1，由于这道题只有整数，所以我们让奇数只能+1，偶数才能/2或者+1做选择，但这时候思考，这两种谁更优呢？
//这也是本题贪心的证明：证明/2是优于+1的，因为x此时为偶数，x+1变成奇数,x+2为偶数，此时想变小，无论加多少偶数次的1，一定要经过/2，假如x+k(k为偶数），start=（x+k）/2，操作次数为k+1
//但此时如果先/2的话，再加上k/2的1就行，操作次数为1+k/2，所以/2优于+1，偶数统一/2，奇数统一+1，重复操作直到target<=startValue后，再startValue-target+循环次数即可
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ret = 0;

        while (target > startValue)
        {
            if (target % 2 == 0)
                target /= 2;
            else
                target++;
            ret++;
        }

        return ret + startValue - target;
    }
};