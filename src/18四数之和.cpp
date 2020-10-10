#include<bits/stdc++.h>
using namespace std;
// 执行用时：76 ms, 在所有 C++ 提交中击败了68.45% 的用户
// 内存消耗：12.6 MB, 在所有 C++ 提交中击败了55.14% 的用户
//只要再固定一个数就可以转化为三数之和，跟15题相比修改target和下标即可
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    if(nums.size() < 4)return {};
    vector<vector<int>> res;
    for(int l = 0; l < (int)nums.size() - 3; l++){
        if(l > 0 && nums[l - 1] == nums[l])continue;
        for(int i = l + 1; i < (int)nums.size() - 2; i++){
            if(i > l + 1 && nums[i - 1] == nums[i])continue;//注意从第二个i开始比较是否重复
            unsigned j = i + 1, k = nums.size() - 1;
            int t = target - nums[i] - nums[l];
            while(j < k){
                if(nums[j] + nums[k] == t){
                    res.push_back({nums[l], nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1])j++;
                    while(j < k && nums[k] == nums[k - 1])k--;
                    j++;k--;
                }else if(nums[j] + nums[k] < t)j++;
                else k--;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums({-2,-1,-1,1,1,2,2});
    fourSum(nums, 0);
    cout << 1 << endl;
}