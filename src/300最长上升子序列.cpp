#include<bits/stdc++.h>
using namespace std;
// 执行用时：100 ms, 在所有 C++ 提交中击败了42.59% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了5.18% 的用户
//O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 1;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j])dp[i] = max(dp[i], dp[j] + 1);
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