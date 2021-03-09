#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了93.86% 的用户
// 内存消耗：7.7 MB, 在所有 C++ 提交中击败了10.12% 的用户
//每当后一天比前一天高，加上差值即可
int maxProfit(vector<int>& prices) {
    if(prices.empty())return 0;
    int n = prices.size();
    int res = 0;
    for(int i = 1; i < n; i++){
        if(prices[i] > prices[i - 1])res += (prices[i] - prices[i - 1]);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}