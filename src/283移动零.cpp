#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了91.02% 的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了5.23% 的用户
//双指针
void moveZeroes(vector<int>& nums) {
    int i = 0, p = 0, n = nums.size();//i是当前遍历的下标，p是下一个非零数存放的位置
    while(i < n){
        if(nums[i]){
            nums[p] = nums[i];
            p++;
        }
        i++;
    }
    while(p < n){
        nums[p] = 0;
        p++;
    }
}

int main(){
    cout << 1 << endl;
}