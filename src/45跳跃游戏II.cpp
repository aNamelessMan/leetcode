#include<bits/stdc++.h>
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了42.47% 的用户
// 内存消耗：16.1 MB, 在所有 C++ 提交中击败了5.10% 的用户
int jump(vector<int>& nums) {
    if(nums.empty())return 0;
    int n = nums.size();
    if(n == 1)return 0;
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    //-1代表无法到达
    //其余值表示到达target的最小值
    for(int i = n - 2; i >= 0; i--){
        //不加这个判断倒数第二个测例会超时，94 / 95 个通过测试用例
        //注意到除了n - 2，当nums[i] - nums[i + 1] == 1时dp[i] = dp[i + 1]
        if(nums[i] - nums[i + 1] == 1 && i != n -2){
            dp[i] = dp[i + 1];
            continue;
        }

        int m = INT_MAX;
        for(int j = i + 1; j <= i + nums[i]; j++){
            if(j == n - 1){
                dp[i] = 1;
                m = INT_MAX;//避免跳出之后dp[i]被再次赋值
                break;
            }
            if(dp[j] != -1){
                m = min(m, dp[j]);
            }
        }
        if(m != INT_MAX ){
            dp[i] = m + 1;
        }
    }
    return dp[0];
}

//暴力dfs不出意料的TLE，毕竟是困难题
//74 / 95 个通过测试用例
int res = INT_MAX;

void dfs(vector<int>& nums, int cur, int steps, int target){
    if(cur > target)return;
    if(cur == target){
        res = min(res, steps);
        return;
    }
    int n = nums[cur];
    if(n == 0)return;
    if(cur + n >= target){
        res = min(res, steps + 1);
        return;
    }
    for(int i = cur + 1; i <= cur + n; i++){
        dfs(nums, i, steps + 1, target);
    }
}

int BFjump(vector<int>& nums) {
    if(nums.empty())return 0;
    int target = nums.size() - 1;
    dfs(nums, 0, 0, target);
    return res;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums1 = {3, 2, 1};
    cout << jump(nums) << endl;
    cout << jump(nums1) << endl;
}