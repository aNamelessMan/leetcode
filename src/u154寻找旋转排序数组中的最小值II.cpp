#include<bits/stdc++.h>
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了92.65% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了12.07% 的用户
int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, h = n - 1;

    while(l < h){
        int mid = l + (h - l) / 2;
        if(nums[mid] > nums[h]){//mid大于最右值时，最小值一定在mid右边
            l = mid + 1;
        }else if(nums[mid] < nums[h]){//mid小于最右值时，最小值一定在mid左边或者就是mid
            h = mid;
        }else{//相等时无法判断，但可以去除h不影响结果，因为还有重复的在范围内
            h--;
        }
    }
    return nums[h];
}

int main(){
    cout << 1 << endl;
}