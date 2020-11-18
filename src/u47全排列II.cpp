#include<bits/stdc++.h>
using namespace std;

//复杂的方法之后再看吧..

// 执行用时：464 ms, 在所有 C++ 提交中击败了5.05% 的用户
// 内存消耗：9.6 MB, 在所有 C++ 提交中击败了12.75% 的用户
//直接在上一题(46)基础上用set来去重...
set<vector<int>> res;
vector<int> tmp;
void dfs(vector<int> &nums, vector<bool> &isIn){
    if(nums.size() == tmp.size())res.insert(tmp);
    for(int i = 0; i < (int)nums.size(); i++){
        if(isIn[i])continue;
        isIn[i] = true;
        tmp.push_back(nums[i]);
        dfs(nums, isIn);
        tmp.pop_back();
        isIn[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    if(nums.empty())return {};
    if(nums.size() == 1)return {nums};
    vector<bool> isIn(nums.size(), false);
    dfs(nums, isIn);

    return vector<vector<int>> (res.begin(), res.end());;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了88.26% 的用户
// 内存消耗：8.8 MB, 在所有 C++ 提交中击败了25.28% 的用户
//直接调库...
vector<vector<int>> cpppermuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    while (next_permutation(nums.begin(), nums.end())) {
        res.push_back(nums);
    }
    return res;
}

int main(){
    cout << 1 << endl;
}