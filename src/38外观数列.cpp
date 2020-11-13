#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了57.01% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了18.93% 的用户
string countAndSay(const string &str){
    int n = str.size();
    string res;
    for(int i = 0; i < n;){//这里不能有i++
        char ch = str[i];int j = 0;
        while(i < n && str[i] == ch){
            i++;
            j++;
        }
        res += to_string(j);
        res += ch;
    }
    return res;
}

string countAndSay(int n) {
    vector<string> dp(n + 1);
    dp[1] = "1";
    for(int i = 2; i <= n; i++){
        dp[i] = countAndSay(dp[i - 1]);
    }
    return dp[n];
}

int main(){
    cout << countAndSay(4) << endl;
}