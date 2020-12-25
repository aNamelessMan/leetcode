#include<bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了29.19% 的用户
// 内存消耗：21.1 MB, 在所有 C++ 提交中击败了18.18% 的用户
int maxProfit(vector<int>& prices) {
    if(prices.empty())return 0;
    int n = prices.size();
    int res = 0;
    for(int i = 1; i < n; i++){
        if(prices[i] > prices[i - 1])res += (prices[i] - prices[i - 1]);
    }
    return res;
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(k > n / 2)return maxProfit(prices);//因为每次交易需要两天，因此允许交易次数大于n/2时，等同于无限次数
    //以上可以防止k太大导致爆栈
    //int dp[n][k + 1][2];//dp[i][k][x]表示第i天结束时，最多允许交易k次时，手上持股情况为x时的最大收益
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    for(int i = 1; i <= k; i++){//第一天无论允许交易多少次，最大收益都是如下
        dp[0][i][0] = 0;
        dp[0][i][1] = -prices[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = k; j > 0; j--) {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        }
    }

    return dp[n - 1][k][0];
}

int main(){
    cout << 1 << endl;
}