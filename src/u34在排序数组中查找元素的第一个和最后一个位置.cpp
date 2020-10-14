#include<bits/stdc++.h>
using namespace std;
// 执行用时：20 ms, 在所有 C++ 提交中击败了76.68% 的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了5.30% 的用户
//不是严格logn先过了再说，有空看题解 https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
int bs(vector<int>& nums, double target, int b, int e){
    if(b > e)return -1;
    int mid = (b + e) / 2;
    if(nums[mid] == target)return mid;
    if(nums[mid] > target){
        return bs(nums, target, b, mid - 1);
    }else{
        return bs(nums, target, mid + 1, e);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    int idx = bs(nums, target, 0, nums.size() - 1);
    if(idx == -1)return {-1, -1};
    int left = idx, right = idx;
    while (left > 0 && nums[left - 1] == nums[idx]) --left;
    while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
    return {left, right};
}

int main(){
    cout << 1 << endl;
}