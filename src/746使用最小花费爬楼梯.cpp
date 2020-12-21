#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了62.43% 的用户
// 内存消耗：13.5 MB, 在所有 C++ 提交中击败了49.56% 的用户
int minCostClimbingStairs(vector<int>& cost) {
    //这里的花费指的是离开第i个台阶所需的花费
    int n = cost.size();
    int dp[n + 1];//dp[i]是到达第i个阶梯的最小花费  所以结果是dp[n]
    dp[0] = dp[1] = 0;
    dp[2] =min(cost[0], cost[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }

    return dp[n];
}

int main(){
    cout << 1 << endl;
}