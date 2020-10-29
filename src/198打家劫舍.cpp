#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了6.28%
//dp[n]代表[0,n]区间能偷的的最大值
//dp[n] = max(dp[n - 1], dp[n - 2] + nums[n])
int rob(vector<int>& nums) {
    if(nums.empty())return 0;
    if(nums.size() < 2)return nums[0];
    int n = nums.size();
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
}

int main(){
    cout << 1 << endl;
}