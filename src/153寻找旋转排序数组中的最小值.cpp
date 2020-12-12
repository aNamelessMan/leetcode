#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了56.15% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了29.83% 的用户
int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, h = n - 1;
    if(nums[h] >= nums[l])return nums[l];//有序或者只有一个元素时直接返回第一个元素

    while(l < h){
        int mid = l + (h - l) / 2 + 1;
        if(nums[mid] < nums[mid - 1])return nums[mid];//小于前一个数说明是就是最小值
        if(nums[mid] >= nums[0]){
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }
    return nums[h];
}

int main(){
    cout << 1 << endl;
}