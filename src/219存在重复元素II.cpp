#include<bits/stdc++.h>
using namespace std;

// 执行用时：76 ms, 在所有 C++ 提交中击败了30.11% 的用户
// 内存消耗：20.8 MB, 在所有 C++ 提交中击败了5.00% 的用户
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> idx;//记录每个数出现的idx
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(idx.count(nums[i]) != 0){
            for(auto x:idx[nums[i]]){
                if(i - x <= k)return true;
            }
        }
        idx[nums[i]].push_back(i);
    }
    return false;
}

int main(){
    cout << 1 << endl;
}