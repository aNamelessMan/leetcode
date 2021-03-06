#include <bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了89.02% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了60.50% 的用户
int maxValue(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //dp[i][j]存的是到grid[i][j]的最大价值
    //每格的值只与其左方和上方的值有关
    //初始化最左行和最上行
    dp[0][0] = grid[0][0];
    for(int i = 1; i < n; i++){
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for(int i = 1; i < m; i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int main(){
    cout << "print sth." << endl;
}