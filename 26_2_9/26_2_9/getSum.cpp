#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//两整数之和
//给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

//异或也代表无进位相加，但要处理进位，则发现(a&b)<<1后再与a^b的结果继续异或，直到(a&b)<<1进位为0，此时异或的结果即为和
class Solution {
public:
    int getSum(int a, int b) {
        int ret = a ^ b;
        unsigned int carry = (a & b) << 1;//用unsigned int防止用int导致的负数左移时符号位溢出的问题

        while (carry)
        {
            int old_ret = ret;
            unsigned int old_carry = carry;

            ret = old_ret ^ old_carry;
            carry = (old_ret & old_carry) << 1;
        }

        return ret;
    }
};