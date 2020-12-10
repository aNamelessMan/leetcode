#include<bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了67.18% 的用户
// 内存消耗：9.7 MB, 在所有 C++ 提交中击败了20.58% 的用户
int singleNumber(vector<int>& nums) {
    int res = 0, n = nums.size();
    for(int i = 0; i < 32; i++){
        int cnt = 0, mask = 1 << i;
        for(int j = 0; j < n; j++){
            if((nums[j] & mask) != 0)cnt++;
        }
        if(cnt % 3 != 0)res |= mask;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}