#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了54.09% 的用户
//在78题基础上  加上40题的去重思路就行了
void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int> &tmp, int start, int n){
    if(start == n)return;
    for(int i = start; i < n; i++){
        if(i != start && nums[i] == nums[i - 1])continue;
        tmp.push_back(nums[i]);
        res.push_back(tmp);
        dfs(nums, res, tmp, i + 1, n);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;

    res.push_back({});
    if(n == 0)return res;

    sort(nums.begin(), nums.end());
    vector<int> tmp;
    dfs(nums, res, tmp, 0, n);

    return res;
}

int main(){
    vector<int> nums({1,2,2});
    subsetsWithDup(nums);
}