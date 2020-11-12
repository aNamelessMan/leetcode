#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了54.14% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了8.06% 的用户
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if(!n || target <= nums[0])return 0;
    for(int i = 0; i < n - 1; i++){
        if(target <= nums[i + 1])return i + 1;
    }
    return n;
}

int main(){
    cout << 1 << endl;
}