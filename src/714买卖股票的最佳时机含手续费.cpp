#include<bits/stdc++.h>
using namespace std;

// 执行用时：516 ms, 在所有 C++ 提交中击败了5.01% 的用户
// 内存消耗：85.8 MB, 在所有 C++ 提交中击败了11.35% 的用户
//详见第123题
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    //dp[i][0]表示在第i天结束时且手中没有股票所能获得的最大收益
    //dp[i][1]表示在第i天结束时且手中持有股票所能获得的最大收益
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][1] + prices[i] - fee, dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }

    return dp[n - 1][0];
}

int main(){
    cout << 1 << endl;
}