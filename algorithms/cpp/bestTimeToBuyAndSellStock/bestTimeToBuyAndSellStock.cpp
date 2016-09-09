// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
* design an algorithm to find the maximum profit.
* 分析：动态规划法。从前向后遍历数组，记录当前出现过的最低价格，作为买入价格，并计算以当天价格出售的收益，作为可能的最大收益，整个遍历过程中，出现过的最大收益就是所求。
*               
**********************************************************************************/

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        
        int maxProfit = 0;
        int curMin = prices[0];
        
        for (int i = 1; i < prices.length; i++) {
            curMin = Math.min(curMin, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i] - curMin);
        }
        
        return maxProfit;
    }
}
