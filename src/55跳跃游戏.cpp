#include<bits/stdc++.h>
using namespace std;
// 执行用时：24 ms, 在所有 C++ 提交中击败了65.56% 的用户
// 内存消耗：12.9 MB, 在所有 C++ 提交中击败了9.36% 的用户
//一遍遍历，不断更新能到达的最大值，直到到达最大值或数组边界
bool canJump(vector<int>& nums) {
    if(nums.size() < 2)return true;
    int curMax = 0;
    int i = 0;
    int t = 0;
    while(i <= curMax && i < (int)nums.size()){
        t = i + nums[i];
        if(t > curMax)curMax = t;
        if(curMax >= (int)nums.size() - 1)return true;
        i++;
    }
    if(i == (int)nums.size())return true;
    else    return false;
}

int main(){
    vector<int> nums({2, 3, 1, 1, 4});
    cout << canJump(nums) << endl;
    vector<int> nums1({3, 2, 1, 0, 4});
    cout << canJump(nums1) << endl;
}