#include<bits/stdc++.h>
using namespace std;

// 执行用时：72 ms, 在所有 C++ 提交中击败了95.78% 的用户
// 内存消耗：19.5 MB, 在所有 C++ 提交中击败了71.08% 的用户
vector<vector<int>> threeSum(vector<int>& nums) {
    //先排序，固定一个数然后双指针  O(n^2)
    //去重时不用考虑太多，第一次遇到nums[i]时就已经把所有包含nums[i]的可能解都遍历了
    int n = nums.size();
    vector<vector<int>> res;
    if(n < 3)return res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1])continue;//去重
        int target = -nums[i], l = i + 1, r = n - 1;
        while(l < r){
            int s = nums[l] + nums[r];
            if(s == target){
                res.push_back({nums[i], nums[l], nums[r]});
                //去重
                while(l + 1 < r && nums[l] == nums[l + 1])l++;
                l++;
                while(r - 1 > l && nums[r] == nums[r - 1])r--;
                r--;
            }else if(s < target){
                l++;
            }else{
                r--;
            }
        }
    }
    return res;
}

// 执行用时：104 ms, 在所有 C++ 提交中击败了75.26% 的用户
// 内存消耗：19.7 MB, 在所有 C++ 提交中击败了43.66% 的用户
//固定一个数后双指针
vector<vector<int>> fstthreeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if(nums.empty() || nums[0] > 0 || nums[nums.size() - 1] < 0)return {};
    vector<vector<int>> res;
    for(int i = 0; i < (int)nums.size() - 2; i++){//这里有一个坑的地方
                //因为之前只是排除了空数组，所以如果nums.size < 2并且i是无符号类型的话
                //会导致 i-2 溢出变成一个很大的值，导致越界
                //所以以后能用int尽量用int，可以正确处理负数情况
                //在这题也可以把判空改成判断是否size小于3
        if(nums[i] >  0)break;
        if(i > 0 && nums[i - 1] == nums[i])continue;
        unsigned j = i + 1, k = nums.size() - 1;
        int target = 0 - nums[i];
        while(j < k){
            if(nums[j] + nums[k] == target){
                res.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j + 1])j++;
                while(j < k && nums[k] == nums[k - 1])k--;
                j++;k--;
            }else if(nums[j] + nums[k] < target)j++;
            else k--;
        }
    }//可以正确处理结果中num[i/j/k]有相同值的情况，不会跳过也不会重复
    return res;
}

int main(){
    unsigned i = 0;
    cout << i - 1 << endl;
}