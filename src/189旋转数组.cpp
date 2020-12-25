#include<bits/stdc++.h>
#include "../dataStruc/vecOps.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了86.75% 的用户
// 内存消耗：10 MB, 在所有 C++ 提交中击败了51.40% 的用户
//这个做法比较巧妙，速度也还行
void rotate(vector<int>& nums, int k) {
    if (nums.empty() || (k %= nums.size()) == 0) return;
    int n = nums.size();
    //翻转两次
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

// 执行用时：232 ms, 在所有 C++ 提交中击败了5.05% 的用户
// 内存消耗：10 MB, 在所有 C++ 提交中击败了44.15% 的用户
//这个算是投机取巧的做法...
void myrotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n <= 1)return;
    k %= n;
    auto iter = nums.begin();
    for(int i = 0; i < n - k; i++){//向右移动k位等于向左移动n-k位
        //见cppp    p315    每次向vector添加元素都可能引起存储空间重新分配，进而导致迭代器失效，因此每次添加元素后都要重新给迭代器赋值
        //否则程序结束时可能会出现  double free or corruption (out) /   munmap_chunk(): invalid pointer之类的错误
        nums.push_back(*iter);
        iter = nums.begin();
        iter = nums.erase(iter);
    }
}

//34 / 35 个通过测试用例    TLE
void BFrotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n <= 1)return;
    //下标为i的元素旋转后的下标应该是 (i+k)%n
    for(int i = 0; i < k; i++){//旋转k次，每次旋转1
        int pre = nums[0], t;
        for(int j = 0; j < n; j++){
            t = nums[(j + 1) % n];
            nums[(j + 1) % n] = pre;
            pre = t;
        }
    }
}

int main(){
    vector<int> nums = {-1, -100, 3, 99};
    rotate(nums, 2);
    printVector(nums);
    nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    printVector(nums);
}