#include <bits/stdc++.h>
using namespace std;

//https://www.cnblogs.com/wsw-seu/p/13700006.html
//比赛时候找到这个博客然后照着写
/**复杂度为O(nlogn)为排序的复杂度
 * 建立前缀和数组，则   前缀和数组中某两个值的差    就是    某子数组和或者某子数组和的相反数    /   子数组和就是前缀和数组的后数减前数
 * 前缀和数组所能产生的最大绝对值   一定是最大值和最小值之间的差值
 *          所能产生的最小绝对值   一定是某两个相邻之间的差值
 * 因此子数组和的最大绝对值 就是排序后首尾相减  或者    前缀和数组中绝对值最大的数的绝对值
 * 另外子数组和的最小绝对值 就是排序后相邻两值的最小差值    或者    前缀和数组中绝对值最小的数的绝对值
 */
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size(), res = 0;
    if(n == 0)return res;
    vector<int> presum;
    presum.push_back(nums[0]);
    for(int i = 1; i < n; i++){
        presum.push_back(presum.back() + nums[i]);
    }
    sort(presum.begin(), presum.end());
    int maxele = 0;
    for(int i:presum){
        if(abs(i) > maxele)maxele = abs(i);
    }
    res = max(maxele, abs(presum[n - 1] - presum[0]));
    return res;
}

//52/64 TLE
/**O(n^2)
 * n = 1e5  n^2 = 1e10 > 1e8因此肯定不可行
 */
int MYmaxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)return 0;
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        dp[i][i] = nums[i];
        for(int j = i + 1; j < n; j++){
            dp[i][j] = dp[i][j - 1] + nums[j];
            res = max(res, dp[i][j]);
            res = max(res, -dp[i][j]);
        }
    }
    return res;
}

int main(){

}