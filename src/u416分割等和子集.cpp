#include<bits/stdc++.h>
using namespace std;
//注意最后需要的两组成分可能都是分隔开的不连续，因此不能用简单的dp存子数组和来求
bool WrongcanPartition(vector<int>& nums) {
    double half = accumulate(nums.begin(), nums.end(),0) / 2.0;
    int dp[nums.size()][nums.size()];//dp[i][j]表示下标从i到j的和，包括i和j
    dp[0][0] = nums[0];
    for(unsigned j = 0; j < nums.size(); j++){
        //dp[0][j] = dp[0][j - 1] + nums[j];if(dp[0][j] == half)return true;
        dp[j][j] = nums[j];if(double(dp[j][j]) == half)return true;
    }
    for(unsigned i = 0; i < nums.size() - 1; i++){
        for(unsigned j = i + 1; j < nums.size(); j++){
            dp[i][j] = dp[i][j - 1] + nums[j];if(double(dp[i][j]) == half)return true;
        }
    }
    return false;
}
// 执行用时：468 ms, 在所有 C++ 提交中击败了58.15% 的用户
// 内存消耗：8.5 MB, 在所有 C++ 提交中击败了96.27% 的用户
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(),0);
    int half = sum / 2;
    //因为是整数数组，所以如果子数组和一定是小数
    if(half * 2 != sum)return false;
    //dp数组值为true表示当前可以表示组成half
    vector<bool> dp(half + 1, false);
    dp[0] = true;//设置0就不用在之后判断j等于nums[i]的情况
    for(unsigned i = 0; i < nums.size(); i++){
        for(int j = half;j >= nums[i]; j--){//必须倒着，确保当前nums[i]只用了一次，否则当nums[i]为1时，dp1到half都会变为true
            if(dp[j - nums[i]])dp[j] = true;
        }
    }
    return dp[half];
}

int main(){
    // vector<int> nums{1,2,3,4,5,6,7};
    vector<int> nums{1,5,11,5};
    //vector<int> nums{23,13,11,7,6,5,5};
    cout << canPartition(nums) << endl;
}