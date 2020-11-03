#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了91.51% 的用户
// 内存消耗：9.2 MB, 在所有 C++ 提交中击败了10.09% 的用户
//双指针
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int p = 0;
    for(int i = 0; i < n; i++){
        if(nums[i]){
            nums[p] = nums[i];
            p++;
        }else{
            while(i < n && !nums[i])i++;
            if(i == n)break;
            nums[p] = nums[i];
            p++;
        }
    }
    while(p < n){
        nums[p] = 0;
        p++;
    }
}

int main(){
    cout << 1 << endl;
}