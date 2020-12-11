#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了18.36% 的用户
void dfs(vector<int> &res, TreeNode* root){
    if(!root)return;
    dfs(res, root->left);
    dfs(res, root->right);
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(res, root);
    return res;
}

int main(){
    cout << 1 << endl;
}