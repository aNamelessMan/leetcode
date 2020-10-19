#include<bits/stdc++.h>
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了46.08% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了6.85% 的用户
int maxSubArray(vector<int>& nums) {
    int thissum = 0, maxsum = 0, m = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        thissum += nums[i];
        if(nums[i] > m)m = nums[i];
        if(thissum > maxsum){
            maxsum = thissum;
        }else if(thissum < 0){
            thissum = 0;
        }
    }
    if(maxsum == 0)return m;
    return maxsum;
}
int main(){
    cout << 1 << endl;
}