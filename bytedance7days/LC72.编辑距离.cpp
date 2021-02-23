#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了81.17% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了39.88% 的用户
//2021.2.23二刷
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j]表示word1.substr[0, i]转换为word1.substr[0, j]的最短编辑距离
    for(int i = 1; i <= m; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= n; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
            else{
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    return dp[m][n];
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.95% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了79.20% 的用户
//dp[word1.size() + 1][word1.size() + 1]
//初始化第一行第一列，代表由空字符串到word1[i]和word2[i]的距离
//每一格的值是它左/左上/上方的最小值加一  从每个方向到达表示不同含义  左代表删除/左上代表替换/上方代表添加
//字符相同无需操作注意dp[i][j]对应的字符是word1[i - 1] word2[j - 1]
int firstminDistance(string word1, string word2) {
    int dp[word1.size() + 1][word2.size() + 1];
    //dp[0][0] = 0;
    for(int i = 0; i <= word1.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= word2.size(); i++){
        dp[0][i] = i;
    }
    for(int i  = 1; i <= word1.size(); i++){
        for(int j  = 1; j <= word2.size(); j++){
            if(word1[i - 1] == word2[j - 1])dp[i][j] = dp[i - 1][j - 1];
            else    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    return dp[word1.size()][word2.size()];
}

int main(){
    cout << 1 << endl;
}