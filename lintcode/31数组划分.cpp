#include<bits/stdc++.h>
using namespace std;

int partitionArray(vector<int> &nums, int k) {
    int n = nums.size();
    if(!n)return 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        if(nums[i] >= k)return i;
    }
    return n;
}

int main(){
    cout << 1 << endl;
}