#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了39.34% 的用户
int fib(int n) {
    if(n == 0)return 0;
    if(n == 1)return 1;
    vector<int> dp = {0, 1};
    int tos = 0;
    n--;
    while(n){
        n--;
        int t = dp[0] + dp[1];
        if(tos){
            dp[1] = t;
            tos = 0;
        }else{
            dp[0] = t;
            tos = 1;
        }
    }
    if(tos){
        return dp[0];
    }else{
        return dp[1];
    }
}

int main(){
    cout << 1 << endl;
}