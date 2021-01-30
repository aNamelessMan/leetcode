#include <bits/stdc++.h>
using namespace std;

//答案正确:恭喜！您提交的程序通过了所有的测试用例
/*
回文串的特点是，逆序输出和正序输出是一样的。
如果将此字符串逆序输出，那么两个字符串的最长公共子序列将是最长的子回文字符串，那么剩余的值将是要删除的字符个数。
所以这道题可以转化为：求该字符串与其逆序字符串的最长公共子序列

即动态规划算法中一个常见的问题最长公共子序列即LCS(Long Common Sequence)
Q：什么是公共子序列？
A：子序列中的每个字符都能在两个原串中找到，而且每个字符的先后顺序和原串中的先后顺序一致。
*/
void dp(){
    string s;
    while(cin >> s){
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        //dp[m][n]表示s[0, m - 1]与r[0, n - 1]的最长公共子序列
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //如果两字符串尾字符相等，则dp[i][j] = dp[i - 1][j - 1] + 1
                if(s[i - 1] == r[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
                else{//否则为max(dp[i - 1][j], dp[i][j - 1])
                /*不等说明两个末尾字符不可能同时在最长公共子串中，因此取    去除其一后的更大值
                */
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << n - dp[n][n] << endl;
    }
}

//自己写的暴力解法
// 内存超限:您的程序使用了超过限制的内存
// case通过率为0.00%
bool isP(string &s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n - 1 - i])return false;
    }
    return true;
}
void BFmethod(){
    string input;
    while(cin >> input){
        //bfs
        queue<string> q;
        q.push(input);
        while(!q.empty()){
            string t = q.front();
            q.pop();
            if(isP(t)){
                cout << input.size() - t.size() << endl;;
                break;
            }
            int n = t.size();
            for(int i = 0; i < n; i++){//去除t中的一个字符后再加入queue中,i是被去除的字符在t中的下标
                q.push(t.substr(0, i) + t.substr(i + 1));
            }
        }
    }
}

int main(){
    //BFmethod();
    dp();
    return 0;
}