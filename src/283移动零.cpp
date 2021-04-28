#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了91.09% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了9.35% 的用户
void moveZeroes20210420(vector<int>& nums) {
    int toput = 0, zeroCnt = 0, n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            zeroCnt++;
        }else{
            nums[toput] = nums[i];
            toput++;
        }
    }
    for(int i = toput; i < n; i++){
        nums[i] = 0;
    }
    return;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.02% 的用户
// 内存消耗：9.3 MB, 在所有 C++ 提交中击败了5.23% 的用户
//双指针
void moveZeroes(vector<int>& nums) {
    int i = 0, p = 0, n = nums.size();//i是当前遍历的下标，p是下一个非零数存放的位置
    while(i < n){
        if(nums[i]){
            nums[p] = nums[i];
            p++;
        }
        i++;
    }
    while(p < n){
        nums[p] = 0;
        p++;
    }
}

int main(){
    cout << 1 << endl;
}