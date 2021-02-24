#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了50.46% 的用户
int cuttingRope(int n) {
    //显然是动态规划
    vector<int> dp(n + 1, 1);//因为长度和段数都大于1所以dp数组应该从2开始
    dp[2] = 1;
    dp[1] = 1;
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= i / 2; j++){
            dp[i] = max({dp[i], dp[i - j] * dp[j], (i - j) * j, dp[i - j] * j, (i - j) * dp[j]});//因为可能某一段比把它分割后的乘积要大，
                                                                //如果不想这么复杂，可以先特殊判断n是否为1/2/3，再把dp[1/2/3]赋值1/2/3,因为从4开始一定是分割后乘积大于等于原来
        }
    }
    return dp[n];
}

int main(){
    cout << "print sth." << endl;
}