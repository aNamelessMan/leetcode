#include<bits/stdc++.h>
using namespace std;
// 执行用时：36 ms, 在所有 C++ 提交中击败了99.90% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了17.13% 的用户
//这种题一看就是动态规划，但是这个递推关系怎么找啊...
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty())return 0;
    int res = 0;
    int m = matrix.size(), n = matrix[0].size();
    //int dp[m][n];
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //dp[i][j]保存以[i,j]为右下角的正方形的最大边长
    //递推关系为dp[i][j] = min(dp[i - 1, j - 1], dp[i - 1, j], dp[i, j - 1]) + 1

    for(int i = 0; i < m; i++){
        if(matrix[i][0] == '1'){
            dp[i][0] = 1;
            res = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(matrix[0][i] == '1'){
            dp[0][i] = 1;
            res = 1;
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == '1'){//"==" 写成了 "="查了半天复制到IDE才找到
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res * res;
}

int main(){
    vector<vector<char>> matrix({{'1','0','1','0','0'}, {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'},});
    cout << maximalSquare(matrix) << endl;
}