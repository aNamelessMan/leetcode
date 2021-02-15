#include <bits/stdc++.h>
using namespace std;
/*
动态规划可以定义为 dp[i, j] 表示这个先手的玩家面临挨到这样的一个区间的分数的时候，我能拿到的最高的分数。这也是博弈类问题的一个特征，就是说我们的动态规划的状态定义是不包含玩家信息的。
也就是与角色是我还是对手无关，矩阵仅仅代表玩家面临这种情况所获得的最大分数

dp[i, j]表示面临nums[i, j]时能取得的最大分数
状态转移方程为:dp[i, j]= max(
    1.  nums[i] + sum[i + 1, j] - dp[i + 1, j]          博弈dp  式子里的dp表示对手所能获得的最多分，剩余的就是你会得到的分数
    2.  nums[j] + sum[i, j - 1] - dp[i, j - 1]
    )
dp矩阵由坐下往右上计算，且j >= i
返回 dp[0, n - 1] >= sum[0, n - 1] - dp[0, n - 1]

初始值为矩阵对角线
*/
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.7 MB, 在所有 C++ 提交中击败了57.18% 的用户
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> sum(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){//初始化
        dp[i][i] = nums[i];
        sum[i][i] = nums[i];
    }
    for(int i = 0; i < n; i++){//每行从对角线开始计算
        for(int j =  i + 1; j < n; j++){
            sum[i][j] = sum[i][j - 1] + nums[j];
        }
    }
    for(int s = 1; s < n; s++){//一条对角线一条对角线的计算
        for(int t = 0; s + t < n; t++){
            int i = t, j = s + t;
            dp[i][j] = max(nums[i] + sum[i + 1][j] - dp[i + 1][j], nums[j] + sum[i][j - 1] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= sum[0][n - 1] - dp[0][n - 1];
}

int main(){
    vector<int> nums{1, 5, 2};
    PredictTheWinner(nums);
    cout << "print sth." << endl;
}