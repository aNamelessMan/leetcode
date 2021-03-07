#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了95.20% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了77.85% 的用户
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 0)return 0;
    int res = 0, mn = prices[0];//mn存在第i天之前的最低价，所以第i天所能赚的最大利润就是当天价格-mn
    for(int i = 0; i < n; i++){
        res = max(res, prices[i] - mn);
        mn = min(mn, prices[i]);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}