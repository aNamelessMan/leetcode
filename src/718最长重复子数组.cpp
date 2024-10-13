#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int row = nums1.size();
        int col = nums2.size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // dp[i][j]数组存的是以 nums1[i]结尾 和 nums2[j]结尾
        // 的最长重复子数组！！！！而非findLength(nums1[0, i], nums2[0, j])!!!!
        // 因此如果两个数字不一样值就一定是0！！！
        dp[0][0] = nums1[0] == nums2[0] ? 1 : 0;
        for (int i = 1; i < row; i++) {
            dp[i][0] = nums1[i] == nums2[0] ? 1 : 0;
            res = max(res, dp[i][0]);
        }
        for (int j = 1; j < col; j++) {
            dp[0][j] = nums1[0] == nums2[j] ? 1 : 0;
            res = max(res, dp[0][j]);
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};