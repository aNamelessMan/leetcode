#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了78.89% 的用户
// 内存消耗：13 MB, 在所有 C++ 提交中击败了44.82% 的用户
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);//dp[i]是只看前i个数 且 包含当前值的最大子序和
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        res = max(res, dp[i]);
    }
    return res;
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了46.08% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了6.85% 的用户
//../剑指offer/42   解法好懂
int maxSubArray(vector<int>& nums) {
    int thissum = 0, maxsum = 0, m = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        thissum += nums[i];
        if(nums[i] > m)m = nums[i];
        if(thissum > maxsum){
            maxsum = thissum;
        }else if(thissum < 0){
            thissum = 0;
        }
    }
    if(maxsum == 0)return m;
    return maxsum;
}
int main(){
    cout << 1 << endl;
}