#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了96.25% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了11.84% 的用户
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1)return 0;
    int n = obstacleGrid.size();
    if(n == 0)return 0;
    int m = obstacleGrid[0].size();
    //相比62题，初始化及递推都要修改
    vector<vector<int>> dp(n, vector<int>(m,0));
    if(obstacleGrid[0][0] == 0)dp[0][0] = 1;
    //初始化时不能简单将边界都设为1，因为有些边界是不可达的
    for(int i = 1; i < m; i++){
        if(obstacleGrid[0][i] == 1 || dp[0][i - 1] == 0)continue;
        dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        if(obstacleGrid[i][0] == 1 || dp[i - 1][0] == 0)continue;
        dp[i][0] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            //递推时只加上不是障碍的左/上值
            if(obstacleGrid[i][j] == 1)continue;
            if(obstacleGrid[i - 1][j] == 0)dp[i][j] += dp[i - 1][j];
            if(obstacleGrid[i][j - 1] == 0)dp[i][j] += dp[i][j - 1];
            //dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main(){
    cout << 1 << endl;
}