#include<bits/stdc++.h>
using namespace std;

//复杂的解法下次再看
// 执行用时：16 ms, 在所有 C++ 提交中击败了50.11% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了57.50% 的用户
int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)return 0;
    sort(nums.begin(), nums.end());
    int res = INT_MIN;
    for(int i = 1; i < n; i++){
        int t = nums[i] - nums[i - 1];
        res = max(res, t);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}