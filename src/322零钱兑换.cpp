#include<bits/stdc++.h>
using namespace std;
// 执行用时：188 ms, 在所有 C++ 提交中击败了10.47% 的用户
// 内存消耗：14.1 MB, 在所有 C++ 提交中击败了19.32% 的用户
int coinChange(vector<int>& coins, int amount) {
    //dp[i]表示凑成金额i的最少硬币数
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    int n = coins.size();
    for(auto &i:coins){
        if(i <= amount)
            dp[i] = 1;
    }
    for(int i = 1; i < amount + 1; i++){
        for(int j = 0; j < n; j++){//注意只用尝试遍历 i-coins[j] 即可，不要遍历之前所有组合
            if(i - coins[j] < 0 || dp[i - coins[j]] == -1)continue;
            else{
                if(dp[i] != -1)    dp[i] = min(dp[i], dp[coins[j]] + dp[i - coins[j]]);
                else dp[i] = dp[coins[j]] + dp[i - coins[j]];
            }
        }
    }
    return dp[amount];
}

int main(){
    cout << 1 << endl;
}