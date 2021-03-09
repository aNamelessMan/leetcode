#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.51% 的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了69.10% 的用户
int part(vector<int>& nums, int l, int h){
    shuffle(nums.begin() + l, nums.begin() + h + 1, std::default_random_engine (2021));//不加这一行会非常慢，复杂度可能退化到O(n^2)，实测会消耗200ms左右
    int toset = l;
    for(int i = l; i < h; i++){
        if(nums[i] < nums[h]){          //遍历需要到达两个目标
            swap(nums[i], nums[toset]); //一是用toset将数组分割成小于和大于nums[toset]的两边
            toset++;                    //二是找到分割的位置
        }
    }
    swap(nums[toset], nums[h]);
    return toset;
}

int findKthLargest(vector<int>& nums, int k) {
    int p = -1, n = nums.size(), l = 0, h = n - 1;
    while(p != n - k){
        p = part(nums, l, h);
        if(p == n - k)break;
        else if(p < n - k){
            l = p + 1;
        }else{
            h = p - 1;
        }
    }
    return nums[p];
} 

// 执行用时：8 ms, 在所有 C++ 提交中击败了94.29% 的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了67.21% 的用户
int BFfindKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main(){
    vector<int> nums{3, 1, 2, 4};
    cout << findKthLargest(nums, 2) << endl;
}