#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.1 MB, 在所有 C++ 提交中击败了24.92% 的用户
vector<vector<int>> res;
vector<int> tmp;
void dfs(vector<int>& nums, int s){
    if(s == (int)nums.size())return;
    for(int i = s; i < (int)nums.size(); i++){
        tmp.push_back(nums[i]);
        res.push_back(tmp);
        dfs(nums, ++s);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    dfs(nums, 0);
    res.push_back({});
    return res;
}

int main(){
    vector<int> nums({1,2,3});
    subsets(nums);
    cout << 1 << endl;
}