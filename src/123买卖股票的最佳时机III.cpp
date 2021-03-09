#include<bits/stdc++.h>
using namespace std;

// 执行用时：816 ms, 在所有 C++ 提交中击败了13.34% 的用户
// 内存消耗：202.2 MB, 在所有 C++ 提交中击败了9.29% 的用户
//2021.3.8二刷自己的解法
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    //dp[i][0/1][0/1/2]是第i天结束时，是否持有股票，还能交易几次的情况下获得的最大收益
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i = 0; i < 3; i++){
        dp[0][1][i] = -prices[0];
    }
    for(int i = 1; i < n; i++){
        dp[i][0][2] = dp[i - 1][0][2];
        dp[i][0][1] = max(dp[i - 1][1][2] + prices[i], dp[i - 1][0][1]);
        dp[i][0][0] = max(dp[i - 1][1][1] + prices[i], dp[i - 1][0][0]);
        dp[i][1][2] = max(dp[i - 1][0][2] - prices[i], dp[i - 1][1][2]);
        dp[i][1][1] = max(dp[i - 1][0][1] - prices[i], dp[i - 1][1][1]);
        dp[i][1][0] = max(dp[i - 1][0][0] - prices[i], dp[i - 1][1][0]);
    }
    return max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][0][2]});
}

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