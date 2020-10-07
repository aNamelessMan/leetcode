#include<bits/stdc++.h>
using namespace std;
//139 / 139 个通过测试用例  TLE
int res = 0;
void dfs(vector<int>& nums, int S, unsigned n, int curSum){
    if(curSum == S && n == nums.size())res++;
    else if(n == nums.size())return;
    else{
        curSum += nums[n];n++;
        dfs(nums, S, n, curSum);
        //注意n和curSum都要还原，而且必须按照这个顺序
        n--;curSum -= nums[n];
        curSum -= nums[n];n++;
        dfs(nums, S, n, curSum);
    }
}
int BFfindTargetSumWays(vector<int>& nums, int S) {
    dfs(nums, S, 0, 0);
    return res;
}
// 执行用时：556 ms, 在所有 C++ 提交中击败了37.51% 的用户
// 内存消耗：49 MB, 在所有 C++ 提交中击败了5.65% 的用户
int findTargetSumWays(vector<int>& nums, int S) {
    //可以用dp来解，dp[i][j]表示0到i为止和为S的方法数
    //i每次+1就要更新在之前基础上所有可能的和值
    int n = nums.size();
    vector<map<int, int>> dp(n + 1);
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(auto &a:dp[i]){
            int sum = a.first, cnt = a.second;
            dp[i + 1][sum - nums[i]] += cnt;
            dp[i + 1][sum + nums[i]] += cnt;
        }
    }
    return dp[n][S];
}

int main(){
    vector<int> nums{1,1,1,1,1};
    int S = 3;
    cout << findTargetSumWays(nums, S) << endl;
}