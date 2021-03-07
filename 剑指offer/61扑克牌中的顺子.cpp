#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了46.35% 的用户
bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0;
    while(i < 5){
        if(nums[i] != 0)break;
        i++;
    }
    if(i == 5)return true;//i是0的个数
    int k = i;
    int prev = nums[i] - 1;
    for(; i < 5; i++){
        if(nums[i] == prev)return false;//有重复一定不连续
        else if(nums[i] - prev - 1 > k)return false;
        else k -= nums[i] - prev - 1;//用去这么多张0
        prev = nums[i];
    }
    return true;
}

int main(){
    cout << "print sth." << endl;
}