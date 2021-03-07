#include <bits/stdc++.h>
using namespace std;

// 执行用时：184 ms, 在所有 C++ 提交中击败了98.62% 的用户
// 内存消耗：98.1 MB, 在所有 C++ 提交中击败了91.19% 的用户
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l <= r){
        int s = nums[l] + nums[r];
        if(s == target)return {nums[l], nums[r]};
        else if(s < target)l++;
        else r--;
    }
    return {-1, -1};
}

int main(){
    cout << "print sth." << endl;
}