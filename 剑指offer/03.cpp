#include<bits/stdc++.h>
using namespace std;

// 执行用时：52 ms, 在所有 C++ 提交中击败了82.04% 的用户
// 内存消耗：26.8 MB, 在所有 C++ 提交中击败了33.66% 的用户
//最简单的方法，使用哈希表，时间和空间复杂度都是O(n)
int firstfindRepeatNumber(vector<int>& nums) {
    unordered_set<int> s;
    for(auto &i:nums){
        if(s.count(i))return i;
        else s.insert(i);
    }
    return -1;
}
// 执行用时：36 ms, 在所有 C++ 提交中击败了97.13% 的用户
// 内存消耗：22.5 MB, 在所有 C++ 提交中击败了86.20% 的用户
//原地查找时间复杂度不变，空间复杂度O(1)
int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] != i){//直到把第i个位置放入数字i
            if(nums[i] == nums[nums[i]])return nums[i];
            else {
                swap(nums[i], nums[nums[i]]);
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums{0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    findRepeatNumber(nums);
    cout << "print something." << endl;
}