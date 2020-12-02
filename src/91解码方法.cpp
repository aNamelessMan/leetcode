#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.6 MB, 在所有 C++ 提交中击败了9.96% 的用户
//这题挺有意思的，很经典的动态规划
bool canMulTran(string &s, int i){//判断第i个字符和他前面的字符能否一起解释
    int t = (s[i - 1] - '0') * 10 + s[i] - '0';
    return (t>=10) && (t <= 26);
}

int numDecodings(string s) {
    int n = s.size();
    if(n == 0 || s[0] == '0')return 0;
    if(n == 1)return 1;
    /*
    dp[i]表示s.substr[0, i]的表示方法个数
    递推关系为
        1.如果s[i]和s[i - 1]能用两种方式解读(即分别单独解释和一起解释)那么dp[i] = dp[i - 1] + dp[i - 2]
        2.如果s[i]只能单独解释  dp[i] = dp[i - 1]
        3.如果s[i]只能一起解释  dp[i] = dp[i - 2]   此时s[i]一定为'0'
        4.s[i]既不能单独解释也不能一起解释  直接返回0   (不能单独解释也就是s[i] == 0)
    初始化如下*/
    vector<int> dp(n, 0);
    dp[0] = 1;//因为s[0]不是0所有一定有且只有一种解释

    if(s[1] != '0' && canMulTran(s, 1))dp[1] = 2;
    else if(s[1] != '0')dp[1] = 1;
    else if(canMulTran(s, 1))dp[1] = 1;
    else return 0;

    for(int i = 2; i < n; i++){
        if(s[i] != '0' && canMulTran(s, i))dp[i] = dp[i - 1] + dp[i - 2];
        else if(s[i] != '0')dp[i] = dp[i - 1];
        else if(canMulTran(s, i))dp[i] = dp[i - 2];
        else return 0;
    }

    return dp[n - 1];
}

//暴力解法
void dfs(int nextstep, int n, string &s, int &res){
    if(nextstep == n){
        res++;
        return;
    }
    if(s[nextstep] == '0')return;
    dfs(nextstep + 1, n, s, res);
    if(nextstep < n - 1){
        int t = s[nextstep] - '0';
        t = 10 * t + s[nextstep + 1] - '0';
        if(t > 0 && t <= 26){
            dfs(nextstep + 2, n, s, res);
        }
    }
}

int BFnumDecodings(string s) {
    int res = 0, n = s.size();
    if(n == 0)return 0;
    dfs(0, n, s, res);
    return res;
}

int main(){
    cout << numDecodings("2611055971756562") << endl;
}