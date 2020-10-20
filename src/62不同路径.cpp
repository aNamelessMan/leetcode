#include<bits/stdc++.h>
using namespace std;
//TLE
int res;
//注意m是列数，n是行数
void dfs(int curm, int curn, int m, int n){
    if(curm == m && curn == n)res++;
    else if(curm == m){curn++;dfs(curm, curn, m, n);}
    else if(curn == n){curm++;dfs(curm, curn, m, n);}
    else{
        curm++;
        dfs(curm, curn, m, n);
        curm--;
        curn++;
        dfs(curm, curn, m, n);
        curn--;
    }
}

int dfsuniquePaths(int m, int n) {
    dfs(1, 1, m, n);
    return res;
}
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.1 MB, 在所有 C++ 提交中击败了61.49% 的用户
//dp    每一格的到达路径数是它左边和上边的路径和，初始化左侧和上侧路径数都是1，然后每行遍历即可
int uniquePaths(int m, int n) {
    int dp[n][m];
    for(int i = 0; i < m; i++){
        dp[0][i] = 1;
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int main(){
    cout << uniquePaths(23, 12) << endl;
}