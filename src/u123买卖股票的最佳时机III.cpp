#include<bits/stdc++.h>
using namespace std;

// 执行用时：1728 ms, 在所有 C++ 提交中击败了5.11% 的用户
// 内存消耗：267 MB, 在所有 C++ 提交中击败了5.03% 的用户
// https://leetcode-cn.com/circle/article/qiAgHn/
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //dp[i][k][0]表示在第i天结束时，最多只进行k次交易且持有0份股票的情况下可以获得的最大收益
    //dp[i][k][1]表示在第i天结束时，最多只进行k次交易且持有1份股票的情况下可以获得的最大收益
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2,0)));
    //初始化    注意dp[i][0][0/1]都已经初始化为0
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];
    //递推关系为：
     for(int i = 1; i < n; i++){
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);//因为想要买入，之前最多只能交易1次
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
    }
    return dp[n - 1][2][0];
}

int main(){
    cout << 1 << endl;
}