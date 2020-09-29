#include<bits/stdc++.h>
using namespace std;

// 执行用时：116 ms, 在所有 C++ 提交中击败了79.72% 的用户
// 内存消耗：31.4 MB, 在所有 C++ 提交中击败了71.15% 的用户
//利用现成的数组来标记出现过的数
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for(int i = 0;i < nums.size(); i++){
        if(nums[i] > 0){
            if(nums[nums[i] - 1] > 0)
                nums[nums[i] - 1] *= -1;
        }else{
            if(nums[-nums[i] - 1] > 0)
                nums[-nums[i] - 1] *= -1;
        }
    }
    for(unsigned i = 0;i < nums.size(); i++){
        if(nums[i] > 0)
            res.push_back(i + 1);
    }
    return res;
}

int main(){
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> res = findDisappearedNumbers(nums);
    for(auto &i:nums){
        cout << i << ",";
    }
    cout << endl;
    for(auto &i:res){
        cout << i << ",";
    }
    cout << endl;
}