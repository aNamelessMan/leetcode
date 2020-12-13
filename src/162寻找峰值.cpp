#include<bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.81% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了6.49% 的用户
//最近找到写二分的感觉2020.12.13
int findPeakElement(vector<int>& nums) {
    //关键应该是返回任何一个峰值所在位置即可
    //为了复杂度为log(n)，显然应该用二分查找，每次判断需要将搜索区间减半
    //需要判断哪一半区间一定包含峰值
    //画图可知，初始情况下，在两边都是负无穷的情况下，显然中间会有峰值
    int n = nums.size();
    if(n == 1)return 0;
    int l = 0, h = n - 1;
    while(l < h){
        int mid = l + (h - l) / 2;
        if(mid != 0 && mid != n - 1){
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])return mid;
            else if(nums[mid] < nums[mid - 1]){
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }else if(mid == 0){
            if(nums[mid] > nums[mid + 1])return mid;
            else{
                l = mid + 1;
            }
        }else{
            if(nums[mid] > nums[mid + 1])return mid;
            else{
                h = mid - 1;
            }
        }
    }
    return h;
}

int main(){
    cout << 1 << endl;
}