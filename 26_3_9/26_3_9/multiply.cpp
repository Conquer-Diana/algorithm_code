#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>


using namespace std;

//字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
//
//示例 1:
//
//输入: num1 = "2", num2 = "3"
//输出 : "6"
//
//示例 2 :
//
//输入 : num1 = "123", num2 = "456"
//输出 : "56088"

//解法一：模拟小学乘法竖式计算

class Solution_1 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        string ret = "0";

        //先将两个字符串都逆置
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        //固定第二个乘数
        for (int i = 0; i < num2.size(); i++)
        {
            string tmp;
            int t = 0, op = i;

            //逆置过来如果是0，则直接下一次循环->处理前导零
            if (num2[i] == '0')
                continue;
            //高位补0，i是几就在前面补几个0
            while (op--)
                tmp += "0";

            //乘以第一个乘数的每一位
            for (int j = 0; j < num1.size(); j++)
            {
                //记录进位
                t += (num1[j] - '0') * (num2[i] - '0');
                tmp += t % 10 + '0';
                t /= 10;
            }
            if (t > 0)
                tmp += t + '0';

            //每得到一个积时，则与ret相加
            int k = 0, cur1 = 0, cur2 = 0;
            string newret;
            while (cur1 < tmp.size() || cur2 < ret.size())
            {
                int a = cur1 < tmp.size() ? tmp[cur1] - '0' : 0;
                int b = cur2 < ret.size() ? ret[cur2] - '0' : 0;
                k += a + b;
                newret += (k % 10) + '0';//使用一个新的ret记录新结果，以防使用ret导致下标越界
                k /= 10;
                cur1++;
                cur2++;
            }
            if (k > 0)
                newret += k + '0';

            ret = newret;//更新ret
        }
        reverse(ret.begin(), ret.end());//最后将ret逆置即最终结果
        return ret;
    }
};

//解法2：在解法一的基础上优化，无进位相乘再相加，最后处理进位
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int m = num1.size(), n = num2.size();
        vector<int> array(m + n - 1, 0);//m位*n位，最后结果为m+n-1位

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                array[i + j] += (num1[j] - '0') * (num2[i] - '0');//先将num1[j]与num2[i]直接相乘不进位，+=到对应的arr[i+j]中

        string ret;
        int t = 0;
        //最后再来处理进位，即数组中的数+进位+0
        for (int i = 0; i < m + n - 1; i++)
        {
            t += array[i];
            ret += t % 10 + '0';
            t /= 10;
        }
        if (t > 0)
            ret += t + '0';

        //逆置之前，ret尾部如果有0（翻转过来就是前导零），直接尾删掉
        while (ret.size() > 1 && ret.back() == '0')
            ret.pop_back();

        //最后逆置即为最终结果
        reverse(ret.begin(), ret.end());
        return ret;

    }
};