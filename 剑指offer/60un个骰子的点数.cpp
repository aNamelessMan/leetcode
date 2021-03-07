#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了85.35% 的用户
/*
动态规划
每一轮某个点数i 组合个数等于上一轮    i - 6/i - 5/i - 4/i - 3/i - 2/i - 1   组合的和
*/

vector<double> dicesProbability(int n) {
    int mn = 1, mx = 6;
    vector<vector<int>> dp(2, vector<int>(6 * n + 1, 0));//存每个和有多少种组合
    for(int i = mn; i <= mx; i++){
        dp[0][i] = 1;
    }
    int flag = 0;//指示上一轮存在dp的哪一行
    for(int i = 1; i < n; i++){
        mn += 1;
        mx += 6;
        for(int j = mn; j <= mx; j++){
            dp[1 - flag][j] = 0;
            for(int k = max(mn - 1, j - 6); k <= j - 1; k++){//注意k只有在上一轮可能出现的范围内才有意义
                dp[1 - flag][j] += dp[flag][k];
            }
        }
        flag = 1 - flag;
    }
    double sum = 1;
    for(int i = 0; i < n; i++){
        sum *= 6;
    }
    vector<double> res;
    for(int i = mn; i <= mx; i++){
        res.push_back(dp[flag][i] / sum);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}