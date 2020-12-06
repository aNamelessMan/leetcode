#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了73.08% 的用户
// 内存消耗：16.5 MB, 在所有 C++ 提交中击败了79.12% 的用户
void dfs(TreeNode* root, int cur, int target, vector<vector<int>> &res, vector<int> &tmp){
    if(!root)return;

    cur += root->val;
    tmp.push_back(root->val);
    if(cur == target && !root->left && !root->right)res.push_back(tmp);

    dfs(root->left, cur, target, res, tmp);
    dfs(root->right, cur, target, res, tmp);

    tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> t;

    dfs(root, 0, sum, res, t);

    return res;
}

int main(){
    cout << 1 << endl;
}