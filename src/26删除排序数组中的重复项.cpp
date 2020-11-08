#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了98.98% 的用户
// 内存消耗：13.7 MB, 在所有 C++ 提交中击败了13.66% 的用户
int removeDuplicates(vector<int>& nums) {
    int p = 0, n = nums.size();
    if(n == 0)return 0;
    for(int i = 0; i < n;){
        int t = nums[i];
        nums[p] = t;p++;
        while(i < n && nums[i] == t)i++;
    }
    return p;
}
// 执行用时：20 ms, 在所有 C++ 提交中击败了62.27% 的用户
// 内存消耗：13.8 MB, 在所有 C++ 提交中击败了9.34% 的用户
int cppremoveDuplicates(vector<int>& nums) {
    int res = 0;
    auto iter = unique(nums.begin(), nums.end());
    for(auto i = nums.begin(); i != iter; i++)res++;
    return res;
}

int main(){
    cout << 1 << endl;
}