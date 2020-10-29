#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了99.06% 的用户
// 内存消耗：11.9 MB, 在所有 C++ 提交中击败了16.03% 的用户
//需要两个dp数组f和g
//f[i]代表0到i且包含i的最大乘积
//g[i]代表0到i且包含i的最小乘积
//包含i的最值只可能在nums[i]    nums[i] * f[i - 1]  nums[i] * g[i - 1]中出现
//还需要保存遍历过程中的最大值作为结果
int maxProduct(vector<int>& nums) {
    int  res = nums[0];
    int n = nums.size();
    int f[n], g[n];
    f[0] = nums[0];
    g[0] = nums[0];
    for(int i = 1; i < n; i++){
        f[i] = max(nums[i], max(nums[i] * f[i - 1], nums[i] * g[i - 1]));
        g[i] = min(nums[i], min(nums[i] * f[i - 1], nums[i] * g[i - 1]));
        res = max(f[i], res);
    }
    return res;
}

//暴力解法  运气好能过，运气不好过不了...
// 执行用时：440 ms, 在所有 C++ 提交中击败了6.52% 的用户
// 内存消耗：12 MB, 在所有 C++ 提交中击败了10.50% 的用户
int maxProduct(vector<int>& nums) {
    if(nums.empty())return 0;
    int res = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int m = 1;
        for(int j = i; j < n; j++){
            m *= nums[j];
            if(m > res)res = m;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}