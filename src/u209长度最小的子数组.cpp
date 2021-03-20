#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了48.31% 的用户
int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX, l = 0, r = 0, cursum = 0, n = nums.size();
    while(r < n){
        while(r < n && cursum < target){
            cursum += nums[r];
            r++;
        }
        while(l < r && cursum >= target){
            res = min(res, r - l);
            cursum -= nums[l];
            l++;
        }
    }
    return res == INT_MAX?0:res;
}

int main(){
    vector<int> nums = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    cout << minSubArrayLen(80, nums) << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << minSubArrayLen(11, nums1) << endl;
}