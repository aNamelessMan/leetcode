#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了63.60% 的用户
// 内存消耗：11.4 MB, 在所有 C++ 提交中击败了62.31% 的用户
/* 详见 https://leetcode-cn.com/problems/gray-code/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--12/
    动态规划，每次新增时原来的数不用变，可以视为在最高位添0，将原来的数颠倒后在最高位添1可以确保只更改1位
*/
vector<int> grayCode(int n) {
    vector<int> dp{0, 1};
    n--;
    while(n){
        int m = dp.size();
        for(int i = m - 1; i >= 0; i--){
            dp.push_back(m + dp[i]);
        }
        n--;
    }
    return dp;
}

// 执行用时：472 ms, 在所有 C++ 提交中击败了5.29% 的用户
// 内存消耗：20.2 MB, 在所有 C++ 提交中击败了6.26% 的用户
vector<int> BFgrayCode(int n) {
    //开头一定是00...00b
    //保存已用过的每个数
    //从第一位开始尝试对每一位取反，未用过则用，用过尝试下一位
    vector<int> res;
    unordered_set<int> used;
    used.insert(0);
    res.push_back(0);

    vector<int> m;
    int t = 1;
    for(int i = 0; i < n; i++){
        m.push_back(t);
        t *= 2;
    }
    int e = 2*t;

    vector<int> pre(n, 0);
    for(int i = 0; i < e; i++){
        for(int j = 0; j < n; j++){
            pre[j] = !pre[j];
            int num = 0;
            for(int k = 0; k < n; k++){
                num += pre[k] * m[k];
            }
            if(!used.count(num)){
                used.insert(num);
                res.push_back(num);
                break;
            }else{
                pre[j] = !pre[j];
                continue;
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}