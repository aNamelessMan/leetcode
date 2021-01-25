#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了91.32% 的用户
// 内存消耗：10.9 MB, 在所有 C++ 提交中击败了96.75% 的用户
int maxProfit(vector<int>& prices) {
    if(prices.empty())return 0;
    //dp[i][2][2]代表第i天结束时 持有/未持有股票 进入/不进入冷冻期 的情况下 所获得的最大收益
    /*
    dp[i][0][0] 未持有股票且不进入冷冻期
    dp[i][0][1] 未持有股票且进入冷冻期  也就是说今天卖出了
    dp[i][1][0] 持有股票一定不会进入冷冻期
    */
   int n = prices.size();
   int dp[n][2][2];
   dp[0][0][0] = 0;
   dp[0][0][1] = INT_MIN;//第一天不可能出现冷冻期，设为最小值，就不影响后续
   dp[0][1][0] = -prices[0];
   for(int i = 1; i < n; i++){
       dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]);//这一回合不进行交易
       dp[i][0][1] = dp[i - 1][1][0] + prices[i];//这一回合卖出
       dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);//这一回合买入或不交易
   }
   return max(dp[n - 1][1][0], max(dp[n - 1][0][0], dp[n - 1][0][1]));
}

int main(){
    cout << "print something." << endl;
}