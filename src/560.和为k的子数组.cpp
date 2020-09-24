#include<bits/stdc++.h>
using namespace std;
//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

//会爆栈
int dpSubarraySum(vector<int>& nums, int k) {
    if(nums.size() == 0)return 0;
    //dp[i, j]代表数组i到j之和  j>=i
    int dp[nums.size()][nums.size()];
    int res = 0;
    for(unsigned i = 0; i < nums.size(); i++){
        for(unsigned j = i; j < nums.size(); j++){
            if(i == j)dp[i][j] = nums[i];
            else    dp[i][j] = dp[i][j - 1] + nums[j];

            if(dp[i][j] == k)res++;
        }
    }
    return res;
}
// 执行用时：124 ms, 在所有 C++ 提交中击败了42.28% 的用户
// 内存消耗：26.1 MB, 在所有 C++ 提交中击败了11.57% 的用户
int subarraySum(vector<int>& nums, int k) {
    int res = 0, sum = 0, n = nums.size();
    unordered_map<int, int> m{{0, 1}};

    //sum是当前累加和，查找之前累加和为sum-k的子数组的个数
    //每有一个这种子数组，一定有一个子数组和为(sum - (sum - k)) = k
    //为了防止出现刚好累加和为k而添加{0， 1}
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        res += m[sum - k];
        ++m[sum]; 
    }
    return res;
}

int main(){
    vector<int> nums{1, 1, 1};//2
    int k = 2;
    cout << subarraySum(nums, k) << endl;
}