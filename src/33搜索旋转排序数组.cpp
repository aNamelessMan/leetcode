#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了80.88% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了6.37% 的用户
int bs(vector<int>& nums, int target, int b, int e){
    if(b == e){
        if(target == nums[b])return b;
        return -1;
    }
    if(nums[b] < nums[e]){//说明此段有序
        if(target < nums[b] || target > nums[e])return -1;
        else {
            int mid = b + (e - b) / 2;
            if(nums[mid] == target)return mid;
            else if(target > nums[mid]){
                return bs(nums, target, mid + 1, e);
            }else{
                return bs(nums, target, b, mid - 1);
            }
        }
    }else{
        int r = bs(nums, target, b, b + (e - b)/2);
        if(r != -1)return r;
        else return bs(nums, target, b + (e - b)/2 + 1, e);
    }
}

int search(vector<int>& nums, int target) {
    if(nums.empty())return -1;
    return bs(nums, target, 0, nums.size() - 1);
}

int main(){
    vector<int> nums{4,5,6,7,0,1,2};
    cout << search(nums, 0) << endl;
    cout << search(nums, 3) << endl;
}