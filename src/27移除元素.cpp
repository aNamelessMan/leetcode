#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了16.11% 的用户
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int p = 0;
    for(int i = 0; i < n; i++){
        while(i < n && nums[i] == val)i++;
        if(i < n && nums[i] != val) nums[p++] = nums[i];
    }
    return p;
}

int main(){
    cout << 1 << endl;
}