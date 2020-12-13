#include<bits/stdc++.h>
using namespace std;

// 执行用时：52 ms, 在所有 C++ 提交中击败了98.56% 的用户
// 内存消耗：14.9 MB, 在所有 C++ 提交中击败了87.78% 的用户
bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)return false;
    sort(nums.begin(), nums.end());
    return unique(nums.begin(), nums.end()) != nums.end();
}

int main(){
    cout << 1 << endl;
}