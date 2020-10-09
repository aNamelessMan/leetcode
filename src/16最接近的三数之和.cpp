#include<bits/stdc++.h>
using namespace std;
// 执行用时：20 ms, 在所有 C++ 提交中击败了52.44% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了39.19% 的用户
//参照15题小改一下就ok
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 40000;//这个数随便选个大点的，不能是INT_MAX，不然后面会溢出
    for(int i = 0; i <(int)nums.size() - 2; i++){
        if(i > 0 && nums[i - 1] == nums[i])continue;
        int j = i + 1, k = nums.size() - 1;
        while(j < k){
            if(abs(nums[i] + nums[j] + nums[k] - target) < abs(res - target))
                res = nums[i] + nums[j] + nums[k];
            if(nums[i] + nums[j] + nums[k] == target)return target;
            else if(nums[i] + nums[j] + nums[k] < target)j++;
            else k--;
        }
    }
    return res;
}

int main(){
    vector<int> nums{1, 1, 1, 1};
    cout << threeSumClosest(nums, -100) << endl;
}