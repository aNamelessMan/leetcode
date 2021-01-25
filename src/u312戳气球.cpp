#include<bits/stdc++.h>
using namespace std;

// 执行用时：792 ms, 在所有 C++ 提交中击败了30.49% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了36.06% 的用户
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 1; len <= n; ++len) {
        //dp[i][j]是nums[i, j]的最大值
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {//便利所有可能取出最大值
                dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
        }
    }
    return dp[1][n];
}

int main(){
    cout << "print something." << endl;
}