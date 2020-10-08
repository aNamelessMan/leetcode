#include<bits/stdc++.h>
using namespace std;
// 执行用时：104 ms, 在所有 C++ 提交中击败了75.26% 的用户
// 内存消耗：19.7 MB, 在所有 C++ 提交中击败了43.66% 的用户
//固定一个数后双指针
vector<vector<int>> threeSum(vector<int>& nums) {
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