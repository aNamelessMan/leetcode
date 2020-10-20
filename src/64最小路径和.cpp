#include<bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了21.31% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了18.37% 的用户
//到达当前格的最小路径是它左边和上边的较小值加上当前值
//初始化左侧和上侧为直线路径和
int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty())return 0;
    int m = grid[0].size(), n = grid.size();
    int dp[n][m];
    dp[0][0] = grid[0][0];
    for(int i = 1; i < m; i++){
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int main(){
    cout << 1 << endl;
}