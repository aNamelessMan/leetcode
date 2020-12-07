#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了89.30% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了73.32% 的用户
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    //dp[i][j]表示  在 s.substr[0, j - 1] 中 t.substr[0, i - 1] 的出现次数  i/j为0表示空字符串
    vector<vector<long>> dp(n + 1, vector<long>(m + 1));
    //初始化第一行为1，因为空字符串是所有字符串的子字符串
    for (int j = 0; j <= m; ++j) dp[0][j] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            /*递推关系：
            1.如果当前遍历的s和t的末尾字符不同，则dp[i][j] = dp[i][j - 1]   
                                            因为如果不同s末尾的字符一定会被舍弃，因此与之前相等
            2.                        相同，则dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
                                            如果相同则可以分为  去除s末尾的情况数dp[i][j - 1]   加上    不去除，即s[j - 1]对应t[i - 1]，剩余部分的情况数为dp[i - 1][j - 1]
            */
            dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        }
    }
    return dp[n][m];
}

int main(){
    cout << 1 << endl;
}