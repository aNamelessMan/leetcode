#include<bits/stdc++.h>
using namespace std;
// 执行用时：40 ms, 在所有 C++ 提交中击败了33.22% 的用户
// 内存消耗：16.9 MB, 在所有 C++ 提交中击败了8.30% 的用户
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(auto &i:nums){
        res ^= i;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}