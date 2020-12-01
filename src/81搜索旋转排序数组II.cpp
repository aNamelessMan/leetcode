#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了95.57% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了28.02% 的用户
bool bs(vector<int>& nums, int target, int l, int h){
    if(l > h)return false;
    int mid = (h - l) / 2 + l;
    if(nums[mid] == target)return true;
    else if(nums[mid] < target)return bs(nums, target, mid + 1, h);
    else return bs(nums, target, l, mid - 1);
}

bool helper(vector<int>& nums, int target, int l, int h){
    if(l > h)return false;
    int mid = (h - l) / 2 + l;
    if(nums[mid] == target)return true;//注意此处需要判断mid处值来不断减小问题，否则当h - l = 1时会无穷递归下去
    else if(nums[l] >= nums[h]){//说明此段无序
        return helper(nums, target, l, mid - 1) || helper(nums, target, mid + 1, h);
    }else{//说明此段有序
        return bs(nums, target, l, h);
    }
}

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)return false;
    return helper(nums, target, 0, n - 1);
}

int main(){
    vector<int> nums = {1, 3, 1, 1, 1};
    search(nums, 3);
    cout << 1 << endl;
}