#include<bits/stdc++.h>
using namespace std;
//注意最后需要的两组成分可能都是分隔开的不连续，因此不能用简单的dp来求子数组和
bool canPartition(vector<int>& nums) {
    double half = accumulate(nums.begin(), nums.end(),0) / 2.0;
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

int main(){
    // vector<int> nums{1,2,3,4,5,6,7};
    //vector<int> nums{1,2,3,5};
    vector<int> nums{23,13,11,7,6,5,5};
    cout << canPartition(nums) << endl;
}