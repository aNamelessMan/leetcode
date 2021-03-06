#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.81% 的用户
// 内存消耗：12.9 MB, 在所有 C++ 提交中击败了46.91% 的用户
int sub(vector<int>& nums, int target, int l, int h){//右闭
    while(l < h){
        int mid = (l + h) / 2 + 1;//向上取整    防止l == mid时无限循环
        if(nums[mid] < target){
            l = mid + 1;
        }else if(nums[mid] > target){
            h = mid - 1;
        }else{
            l = mid;
        }
    }
    return h;//正常情况下l==h，但有些情况(不存在该数)返回l可能越界，下面同理
}

int slb(vector<int>& nums, int target, int l, int h){//左闭
    while(l < h){
        int mid = (l + h) / 2;
        if(nums[mid] < target){
            l = mid + 1;
        }else if(nums[mid] > target){
            h = mid - 1;
        }else{
            h = mid;
        }
    }
    return l;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0)return 0;
    int lb = slb(nums, target, 0, n - 1);
    if(nums[lb] != target)return 0;//防止数组中不存在该数，此时ub - lb + 1无意义是个错误值
    int ub = sub(nums, target, 0, n - 1);
    return ub - lb + 1;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.81% 的用户
// 内存消耗：12.9 MB, 在所有 C++ 提交中击败了68.84% 的用户
int BFsearch(vector<int>& nums, int target) {
    int res = 0;
    for(int i:nums){
        if(i == target)res++;
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}