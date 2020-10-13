#include<bits/stdc++.h>
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了40.85% 的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了5.07% 的用户
//并没有比一遍搜索更快
int bs(vector<int>& nums, int target, int b, int e){
    if(b == e){
        if(target == nums[b])return b;
        return -1;
    }
    if(nums[b] < nums[e]){//说明此段有序
        if(target < nums[b] || target > nums[e])return -1;
        else {
            int r = bs(nums, target, b, b + (e - b)/2);//注意b和e的中点坐标一般情况下不是e/2，而是b + (e - b)/2
            if(r != -1)return r;
            else return bs(nums, target, b + (e - b)/2 + 1, e);
        }
    }else{
        int r = bs(nums, target, b, b + (e - b)/2);
        if(r != -1)return r;
        else return bs(nums, target, b + (e - b)/2 + 1, e);
    }
}

int search(vector<int>& nums, int target) {
    if(nums.empty())return -1;
    return bs(nums, target, 0, nums.size() - 1);
}

int main(){
    vector<int> nums{4,5,6,7,0,1,2};
    cout << search(nums, 0) << endl;
    cout << search(nums, 3) << endl;
}