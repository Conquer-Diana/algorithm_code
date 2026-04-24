#define _CRT_SECURE_NO_WARNINGS


#include <vector>

using namespace std;

//买卖股票的最佳时机_4
//给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//示例 1：
//
//输入：k = 2, prices = [2, 4, 1]
//输出：2
//解释：在第 1 天(股票价格 = 2) 的时候买入，在第 2 天(股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4 - 2 = 2 。
//
//示例 2：
//
//输入：k = 2, prices = [3, 2, 6, 5, 0, 3]
//输出：7
//解释：在第 2 天(股票价格 = 2) 的时候买入，在第 3 天(股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6 - 2 = 4 。
//随后，在第 5 天(股票价格 = 0) 的时候买入，在第 6 天(股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3 - 0 = 3 。

//该题是《买卖股票的最佳时机_3》的升级Plus版，就是把2次交易，扩充到了k次交易
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //由于给的k次交易，对于天数（prices.size()）来说，可能交易不到k那么多次，最多交易（n/2）次，所以可以对k进行一次取最小值的优化
        k = min(k, n / 2);

        vector<vector<int>> buy(n, vector<int>(k + 1)), sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0], sell[0][0] = 0;
        for (int j = 1; j < k + 1; j++)
            buy[0][j] = sell[0][j] = -0x3f3f3f3f;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < k + 1; j++)
            {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = sell[i - 1][j];
                if (j - 1 >= 0)
                    sell[i][j] = max(sell[i][j], buy[i - 1][j - 1] + prices[i]);
            }

        int ret = 0;
        for (int j = 0; j < k + 1; j++)
            ret = max(ret, sell[n - 1][j]);

        return ret;
    }
};