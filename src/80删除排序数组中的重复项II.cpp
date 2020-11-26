#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了91.97% 的用户
// 内存消耗：11 MB, 在所有 C++ 提交中击败了9.41% 的用户
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int r = 0;//i是下一个元素存放的位置
    for(int i = 0; i < n;){
        int base = nums[i], cnt = 0;
        while(i < n && nums[i] == base){
            if(cnt < 2){
                swap(nums[i], nums[r]);
                r++;
            }
            i++;
            cnt++;
        }
    }
    return r;
}

int main(){
    cout << 1 << endl;
}