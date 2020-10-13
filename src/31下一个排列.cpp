#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了66.00% 的用户
// 内存消耗：12.2 MB, 在所有 C++ 提交中击败了13.31% 的用户

//排列变大需要将一个更大更靠后的数与前面的一个更小的数交换 
//下一个更大的序列，也就是尽可能接近，尽可能找到在低位的数字与它之后的数字交换，并把交换后前面那个数字后面升序排列，确保尽可能小
void nextPermutation(vector<int>& nums) {
    if(nums.size() < 2)return;
    int i;
    for(i = 0; i < (int)nums.size() - 1; i++){
        if(nums[i] < nums[i + 1])break;
    }
    if(i == (int)nums.size() - 1){
        sort(nums.begin(), nums.end());
        return;
    }
    //从倒数第二位开始寻找后面是否有更大值，找到就交换并return，因此当前i之后的值都是降序排列
    for(i = nums.size() - 2; i > -1; i--){
        if(nums[i] < nums[i + 1]){
            for(int j = nums.size() - 1; j > i; j--){
                if(nums[j] > nums[i]){
                    int tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
    }
}

int main(){
    vector<int> nums{2, 3, 1};
    nextPermutation(nums);
    auto iter = nums.begin();
    while(iter != nums.end()){
        cout << *iter << ",";
        iter++;
    }
}