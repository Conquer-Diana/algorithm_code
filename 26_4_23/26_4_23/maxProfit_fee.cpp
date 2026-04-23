#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//买卖股票的最佳时机含手续费
//给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
//
//你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//
//返回获得利润的最大值。
//
//注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
//
//示例 1：
//输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出：8
//解释：能够达到的最大利润 :
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润 : ((8 - 1) - 2) + ((9 - 4) - 2) = 8
//
//示例 2：
//输入：prices = [1, 3, 7, 5, 10, 3], fee = 3
//输出：6

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        //buy[i]表示第i天结束后，是“买入”状态，该状态下的最大利润
        //sell[i]表示第i天结束后，是“卖出”状态，该状态下的最大利润
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0], sell[0] = 0;

        //状态机
        //第i天要处于买入状态，要么是第i-1天啥也不做，要么是i-1天处于卖出状态时，买入了一只股票，减去当天的股票价格
        //第i天要处于卖出状态，要么是第i-1天啥也不做，要么是i-1天处于买入状态时，卖出了一只股票，加上当天的股票价格
        //注意：因为有手续费的存在，所以需要在这两次中的任意一次减去手续费
        for (int i = 1; i < n; i++)
        {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
        }

        return sell[n - 1];//最终肯定是卖出状态时，有最大利润（处于买入状态时，还有股票没卖出去）
    }
};