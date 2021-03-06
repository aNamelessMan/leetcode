#include <bits/stdc++.h>
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了89.89% 的用户
// 内存消耗：16.7 MB, 在所有 C++ 提交中击败了57.24% 的用户
int missingNumber(vector<int>& nums) {
    /**因为是递增、元素唯一且每个数字都在范围0～n-1之内，因此只有下面一种情况
    [0, 1, 3, 4]二分找到那个分界点下标即可(此例为2)
    */
    int n = nums.size();
    int l = 0, h = n - 1;
    while(l < h){
        int mid = (l + h) / 2;
        if(nums[mid] == mid){
            l = mid + 1;
        }else{
            h = mid;
        }
    }
    return nums[l] == l?n:l;//nums[l]==l对应没有分界点的情况，也可以看成是分界线为n
}

int main(){
    cout << "print sth." << endl;
}