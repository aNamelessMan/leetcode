#include<bits/stdc++.h>
using namespace std;

// 您的提交打败了 96.80% 的提交!
int findMin(vector<int> &nums) {
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        if(nums[i] > nums[i + 1])return nums[i + 1];
    }
    return nums[0];
}

int main(){
    cout << 1 << endl;
}