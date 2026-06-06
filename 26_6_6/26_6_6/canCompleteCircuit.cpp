#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//加油站
//在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//
//给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1 。如果存在解，则 保证 它是 唯一 的。
//
//示例 1:
//输入: gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]
//输出 : 3
//解释 :
//	从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//	开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//	开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//	开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//	开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//	开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//	因此，3 可为起始索引。
//
//示例 2:
//输入: gas = [2, 3, 4], cost = [3, 4, 3]
//输出 : -1
//解释 :
//	你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
//	我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
//	开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
//	开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
//	你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
//	因此，无论怎样，你都不可能绕环路行驶一周。

//暴力解：只需要判断diff=gas-cost的收益为准，由于是要绕环，所以需要用i+step来%n
//时间复杂度O(n^2)
class Solution_1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++)//遍历起点
        {
            int rest = 0, step = 0;
            for (step = 0; step < n; step++)//绕环
            {
                int index = (i + step) % n;
                rest += gas[index] - cost[index];
                if (rest < 0)//一出现负收益就跳出
                    break;
            }
            //如果是正收益出循环的，则直接返回下标
            if (rest >= 0)
                return i;
        }
        //里面都没有返回，则直接返回-1
        return -1;
    }
};

//贪心优化策略，假如diff[a,b,c,d,e,f,g,h,i],如果到f这里，rest<0了，则有a+b+c+d+e>0,a+b+c+d+e+f<0了，则a和f这中间的数其实没有必要再遍历了，因为a>0，所以b+c+d+e+f也小于0，rest小于0的话可以直接将i跳到i+step+1位置
//这样最差情况，也只是遍历数组两边，时间复杂度降为了O(n)
class Solution_2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            int rest = 0, step = 0;
            for (step = 0; step < n; step++)
            {
                int index = (i + step) % n;
                rest += gas[index] - cost[index];
                if (rest < 0)
                    break;
            }
            if (rest >= 0)
                return i;
            i += step;//优化
        }
        return -1;
    }
};