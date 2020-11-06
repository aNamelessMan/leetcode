#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了13.37% 的用户
//相较于之前    只需把首尾分别去掉后调用之前的程序，取两次结果的最大值
//注意只有一个元素的特殊情况(即首尾是同一个元素)
int easyrob(vector<int>& nums) {
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
int rob(vector<int>& nums) {
    if(nums.size() == 1)return nums[0];
    int t = nums[0];
    nums[0] = 0;
    int r1 = easyrob(nums);
    nums[0] = t;
    nums[nums.size() - 1] = 0;
    int r2 = easyrob(nums);
    return max(r1, r2);
}

int main(){
    cout << 1 << endl;
}