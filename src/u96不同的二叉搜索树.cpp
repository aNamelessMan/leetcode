#include<bits/stdc++.h>
using namespace std;
//这个叫卡塔兰数，应该只能靠记住了，现推时间紧张也很难而且没必要
int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;//注意初始化，dp里是随机值
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main(){
    cout << 1 << endl;
}