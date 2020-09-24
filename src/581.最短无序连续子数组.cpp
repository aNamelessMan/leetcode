#include<bits/stdc++.h>
using namespace std;
// 执行用时：108 ms, 在所有 C++ 提交中击败了31.59% 的用户
// 内存消耗：25.7 MB, 在所有 C++ 提交中击败了29.94% 的用户
int findUnsortedSubarray(vector<int>& nums) {
    vector<int>cp(nums);
    sort(cp.begin(), cp.end());
    unsigned i, j;
    for(i = 0; i < nums.size(); i++){
        if(cp[i] != nums[i])break;
    }
    //直到越界仍然相同，说明有序
    if(i == nums.size())return 0;
    for(j = nums.size() - 1; j >= 0; j--){
        if(cp[j] != nums[j])break;
    }
    return j - i + 1;
}
int main(){
    vector<int> nums{1, 2, 3, 4};//5
    cout << findUnsortedSubarray(nums) << endl;
}