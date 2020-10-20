#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了19.13% 的用户
//每个的到达方法是到达它前两格的和
//初始化第一格为和第二格为2
int climbStairs(int n) {
    if(n == 1)return 1;
    if(n == 2)return 2;
    int dp[n + 1];
    dp[1] = 1;dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(){
    cout << 1 << endl;
}