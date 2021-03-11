#include <bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了98.29% 的用户
// 内存消耗：22.2 MB, 在所有 C++ 提交中击败了99.76% 的用户
int maxSubArray(vector<int>& nums) {
    int res = INT_MIN, n = nums.size(), cursum = 0;//cursum是包含当前遍历元素的情况下且只考虑之前元素的最大子数组和
    for(int i = 0; i < n; i++){
        cursum = max(nums[i], cursum + nums[i]);
        res = max(res, cursum);
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}