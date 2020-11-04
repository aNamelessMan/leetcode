#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了98.02% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了17.93% 的用户
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < 32; i++){//统计重复数的为1的位
        int bit = 1 << i;
        int c1 = 0, c2 = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] & bit)c1++;//统计nums中此位为1的数的个数
            if(j & bit)c2++;//统计0到n-1中此位为1的数的个数
        }
        if(c2 < c1)res += bit;//c1 > c2说明重复的数此位为1
    }
    return res;
}

int main(){
    cout << 1 << endl;
}