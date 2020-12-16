#include<bits/stdc++.h>
using namespace std;

//您的提交打败了 34.20% 的提交!
int kthSmallest(int k, vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}

int main(){
    cout << 1 << endl;
}