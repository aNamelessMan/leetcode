#include<bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了32.07% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了57.18% 的用户
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    //逆着推，dp[i][j]代表从此处到达右下角所需的最低血量
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = 1; dp[m - 1][n] = 1;//从这两格可以退回右下角
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    return dp[0][0];
}

//暴力解法  41 / 45 个通过测试用例  TLE
void dfs(int i, int j, int curmin, int &res, int cur, vector<vector<int>>& dungeon, int m, int n){//i,j是当前所在的横纵坐标
    if(i == m && j == n){
        res = max(res, curmin);
        return;
    }
    if(i < m){
        cur += dungeon[i + 1][j];
        dfs(i + 1, j, min(curmin, cur), res, cur, dungeon, m, n);
        cur -= dungeon[i + 1][j];
    }
    if(j < n){
        cur += dungeon[i][j + 1];
        dfs(i, j + 1, min(curmin, cur), res, cur, dungeon, m, n);
        cur -= dungeon[i][j + 1];
    }
}

int BFcalculateMinimumHP(vector<vector<int>>& dungeon) {
    //也就是计算    到达右下角的各个路径过程中的最小值  的最大值
    int curmin = dungeon[0][0], res = INT_MIN;
    int m = dungeon.size(), n = dungeon[0].size();
    dfs(0, 0, curmin, res, curmin, dungeon, m - 1, n - 1);
    return res >= 0 ? 1:-res + 1;
}

int main(){
    cout << 1 << endl;
}