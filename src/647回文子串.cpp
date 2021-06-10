#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了65.17% 的用户
//  2021.6.10   暴力解法
int countSubstrings(string s) {
    int res = 0, n = s.size(), i = 0;
    while(i < n){
        //i作为对称轴
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
            res++;
        }
        //i 和 i+1 作为对称轴
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
            res++;
        }
        i++;
    }
    return res;
}

//动态规划
// 执行用时：24 ms, 在所有 C++ 提交中击败了39.31% 的用户
// 内存消耗：10.5 MB, 在所有 C++ 提交中击败了22.57% 的用户
int countSubstrings(string s) {
    if(!s.size())return 0;
    //dp[i][j]表示子串s.sub(i, j + 1)是不是回文串
    int dp[s.size()][s.size()];
    int sum = 0;
    for(unsigned d = 0; d < s.size(); d++){
        for(unsigned i = 0, j = i + d; j < s.size(); i++, j++){
            if(d == 0)dp[i][j] = 1;
            else if(d == 1)dp[i][j] = (int)(s[i] == s[j]);
            else dp[i][j] = (int)(s[i] == s[j] && dp[i + 1][j - 1]);
            sum += dp[i][j];
        }
    }
    return sum; 
}

int main(){
    cout << countSubstrings("") << endl;
}