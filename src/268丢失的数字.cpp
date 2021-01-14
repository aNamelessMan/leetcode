#include<bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：17.5 MB, 在所有 C++ 提交中击败了98.44% 的用户
/*
为了写常数空间复杂度错了好多次...
基本思路很简单，常数空间肯定就是用数组本身来标记这个数是否出现过
每遍历一个数i，就将nums[i]变为负数
    特殊情况
        nums[i]为0时，需要单独判断i是否存在，因为0取负仍然不是负数
        单独判断n是否存在
*/
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    bool nExist = false;
    int zidx = -1;
    for(int i = 0; i < n; i++){
        if(nums[i] == 0)zidx = i;
    }
    if(zidx == -1)return 0;
    bool zidxExist = false;
    for(int i = 0; i < n; i++){
        if(nums[i] == zidx)zidxExist = true;
    }
    if(!zidxExist)return zidx;
    for(int i = 0; i < n; i++){
        if(nums[i] == n || nums[i] == -n)nExist = true;
        else{
            nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
        }
    }
    if(!nExist)return n;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0)return i;
    }
    return -1;
}

int main(){
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << missingNumber(nums) << endl;
}