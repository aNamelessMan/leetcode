#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了93.43% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了54.62% 的用户
int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0, r = 0, n = nums.size(), res = n + 1, sum = 0;
    if(n == 0)return 0;
    while(r < n){//先扩张再收缩
        while(sum < s && r < n){
            sum += nums[r];
            r++;
        }
        while(sum >= s){
            res = min(res, r - l);
            sum -= nums[l];
            l++;
        }
    }
    return res == n + 1 ? 0 : res;
}

int main(){
    vector<int> nums = {10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    cout << minSubArrayLen(80, nums) << endl;
}