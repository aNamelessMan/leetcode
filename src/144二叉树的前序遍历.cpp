#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
//递归解法，迭代解法有时间再看
void dfs(TreeNode* root, vector<int> &res){
    if(!root)return;
    res.push_back(root->val);
    dfs(root->left,res);
    dfs(root->right,res);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}