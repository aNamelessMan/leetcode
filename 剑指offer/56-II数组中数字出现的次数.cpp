#include <bits/stdc++.h>
using namespace std;

// 执行用时：44 ms, 在所有 C++ 提交中击败了72.92% 的用户
// 内存消耗：15.8 MB, 在所有 C++ 提交中击败了63.48% 的用户
int singleNumber(vector<int>& nums) {
    vector<int> cnt(32, 0);
    for(int i:nums){
        unsigned bit = 1;
        for(int j = 0; j <= 31; j++){
            if(i & bit)cnt[j]++;
            bit <<= 1;
        }
    }
    unsigned res = 0;
    for(int i = 31; i >= 0; i--){
        res <<= 1;
        if(cnt[i] % 3)res += 1;
    }
    return res;
}

int main(){
    vector<int> nums{3, 4, 3, 3};
    cout << singleNumber(nums) << endl;
}