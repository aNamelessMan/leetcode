#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了95.41% 的用户
// 内存消耗：13 MB, 在所有 C++ 提交中击败了8.73% 的用户
//当前所能取得的最大利润是在这之前的最小值与今天的差
int res = INT_MIN;
int maxProfit(vector<int>& prices) {
    if(prices.empty())return 0;
    int n = prices.size();
    int dp[n];//用于保存到当前为止的最小值
    dp[0] = prices[0];
    for(int i = 1; i < n; i++){
        if(prices[i] < dp[i - 1])dp[i] = prices[i];
        else dp[i] = dp[i - 1];//!!!!!!!!注意这一步不要忘，最小值不更新也需要赋值
        int tmp = prices[i] - dp[i - 1];
        if(tmp > res)res = tmp;
    }
    if(res < 0)return 0;
    return res;
}

int main(){
    cout << 1 << endl;
}