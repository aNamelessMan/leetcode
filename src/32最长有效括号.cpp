#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了46.34% 的用户
//2021.3.1  题解的做法  O(n)
int longestValidParentheses(string s) {
    int n = s.size();
    if(n == 0)return 0;
    vector<int> dp(n, 0);
    /*dp[i]表示以s[i]为结尾字符的最长有效子串
    显然有效子串的结尾字符必须是')' 
    dp[i] = 
        1.前一个字符为'('时，则dp[i] = dp[i - 2] + 2 
        2.前一个字符为')'时，   若s[i−dp[i−1]−1]='('，那么dp[i] = dp[i - 1] + dp[i−dp[i−1]−2] + 2   也就是 子串 + '(' + 子串 + ')'
                                                  否则为0
    */
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        if(s[i] == '('){
            dp[i] = 0;
        }else{
            if(s[i - 1] == '('){
                if(i - 2 >= 0){
                    dp[i] = dp[i - 2] + 2;
                }else{
                    dp[i] = 2;
                }
            }else{
                if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
                    if(i - dp[i - 1] - 2 >= 0){
                        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                    }else{
                        dp[i] = dp[i - 1] + 2;
                    }
                }else{
                    dp[i] = 0;
                }
            }
        }
    }
    int res = 0;
    for(auto i:dp){
        res = max(res, i);
    }
    return res;
}

// 执行用时：1420 ms, 在所有 C++ 提交中击败了5.13% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了85.12% 的用户
//暴力法，O(n^2)竟然能过...
//当前子串中左括号数量大于右括号数量之后才可能有效
int BFlongestValidParentheses(string s) {
    if(s.empty())return 0;
    int maxlen = 0;
    for(int i = 0; i < (int)s.size() - 1; i++){
        if(s[i] == ')')continue;
        int l = 1, r = 0;
        for(int j = i + 1; j < (int)s.size(); j++){
            if(s[j] == '(')l++;
            else r++;
            if(r > l)break;//如果右多于左肯定无效
            else if(r == l){//左右相等是一个有效括号串
                int len = j - i + 1;
                if(len > maxlen){
                    maxlen = len;
                }
            }//其余情况继续循环
        }
    }
    return maxlen;
}

int main(){
    cout << longestValidParentheses("(()") << endl;
    cout << longestValidParentheses(")()())") << endl;
}