#include<bits/stdc++.h>
using namespace std;
// 执行用时：100 ms, 在所有 C++ 提交中击败了42.59% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了5.18% 的用户
//O(n^2)
int lengthOfLIS(vector<int>& nums) {
    //dp[i]是以nums[i]为结尾的最长子序列长度，初始化为1
    //递推关系如下
    //对于每一个i遍历前面的所有数nums[j]，如果nums[j] < nums[i] dp[i] = max(dp[i], dp[j] + 1);
    if(nums.empty())return 0;
    int res = 1;
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i])dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }

    return res;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了97.21% 的用户
// 内存消耗：10 MB, 在所有 C++ 提交中击败了99.12% 的用户
//O(nlog(n))的解法，应该是想不到了
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
        if(iter == dp.end()){
            dp.push_back(nums[i]);
        }else{
            *iter = nums[i];
        }
    }
    return dp.size();
}

int main(){
    cout << 1 << endl;
}