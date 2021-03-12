#include<bits/stdc++.h>
using namespace std;
//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

//83 / 89 个通过测试用例    TLE
//复杂度O(n^2)
int BFsubarraySum(vector<int>& nums, int k) {
    int n = nums.size(), res = 0;
    vector<int> presum(n);
    presum[0] = nums[0];
    if(presum[0] == k)res++;
    for(int i = 1; i < n; i++){
        presum[i] = nums[i] + presum[i - 1];
        if(presum[i] == k)res++;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(presum[j] - presum[i] == k)res++;
        }
    }
    return res;
}

// 执行用时：124 ms, 在所有 C++ 提交中击败了42.28% 的用户
// 内存消耗：26.1 MB, 在所有 C++ 提交中击败了11.57% 的用户
int subarraySum(vector<int>& nums, int k) {
    int res = 0, sum = 0, n = nums.size();
    unordered_map<int, int> m{{0, 1}};//m存的是前缀和值的个数   因此当当前前缀和为sum时，以当前值为末尾且和为k的子数组个数  就是之前前缀和为    sum - k 的个数

    //sum是当前累加和，查找之前累加和为sum-k的子数组的个数
    //每有一个这种子数组，一定有一个子数组和为(sum - (sum - k)) = k
    //为了防止出现刚好累加和为k而添加{0， 1}
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        res += m[sum - k];
        ++m[sum]; 
    }
    return res;
}

int main(){
    vector<int> nums{1, 1, 1};//2
    int k = 2;
    cout << subarraySum(nums, k) << endl;
}