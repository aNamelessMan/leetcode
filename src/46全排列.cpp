#include<bits/stdc++.h>
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了88.74% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了14.65% 的用户
vector<vector<int>> res;
vector<int> tmp;
void dfs(vector<int> &nums, vector<bool> &isIn){
    if(nums.size() == tmp.size())res.push_back(tmp);
    for(int i = 0; i < (int)nums.size(); i++){
        if(isIn[i])continue;
        isIn[i] = true;
        tmp.push_back(nums[i]);
        dfs(nums, isIn);
        tmp.pop_back();
        isIn[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    if(nums.empty())return {};
    if(nums.size() == 1)return {nums};
    vector<bool> isIn(nums.size(), false);
    dfs(nums, isIn);
    return res;
}

int main(){
    cout << 1 << endl;
}