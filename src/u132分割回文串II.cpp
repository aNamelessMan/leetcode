#include<bits/stdc++.h>
using namespace std;

// 执行用时：56 ms, 在所有 C++ 提交中击败了78.78% 的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了38.38% 的用户
int minCut(string s) {
    if (s.empty()) return 0;
    int n = s.size();
//p[i][j] 表示区间 [i, j] 内的子串是否为回文串，其状态转移方程为 p[i][j] = (s[i] == s[j]) && p[i+1][j-1]
//这里的i，j和下面的i，j是颠倒过来的
//所以这里的i是从大
    vector<vector<bool>> p(n, vector<bool>(n));
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {//每新增一个字符，看它是否能和前面的字符构成回文串，能则更新dp
        dp[i] = i;
        for (int j = 0; j <= i; ++j) {
            if (s[i] == s[j] && (j + 1 > i - 1 || p[j + 1][i - 1])) {//判断从尾部往前的子串是不是回文串
                p[j][i] = true;
                dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);//j为0则s[i, j]是回文串，分割次数为0；
            }
        }
    }
    return dp[n - 1];
}

//24 / 29 个通过测试用例    TLE
//改了下131题的解法
bool isP(string s){
    int n = s.size();
    if(n == 1)return true;
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1])return false;
    }
    return true;
}

void dfs(int start, int n, vector<int> &res, int &t, string &s){
    if(start == n){
        res.push_back(t);
        return;
    }
    for(int l = 1; start + l <= n; l++){
        if(isP(s.substr(start, l))){
            t++;
            dfs(start + l, n, res, t, s);
            t--;
        }
    }
}

int BFminCut(string s) {
    int n = s.size();
    vector<int> res;
    int t = 0;

    dfs(0, n, res, t, s);

    auto iter = min_element(res.begin(), res.end());

    return *iter;
}

int main(){
    cout << BFminCut("aab") << endl;
}