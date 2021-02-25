#include <bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了91.16% 的用户
// 内存消耗：17.7 MB, 在所有 C++ 提交中击败了73.86% 的用户
vector<int> exchange(vector<int>& nums) {
    int toset = 0, n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] % 2){
            std::swap(nums[toset], nums[i]);
            toset++;
        }
    }
    return nums;
}

int main(){
    cout << "print sth." << endl;
}