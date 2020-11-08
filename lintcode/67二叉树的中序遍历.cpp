#include<bits/stdc++.h>
#include "../src/TreeNode.hpp"
using namespace std;

//您的提交打败了 95.00% 的提交!
void dfs(TreeNode * root, vector<int> &res){
    if(!root)return;
    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
}
vector<int> inorderTraversal(TreeNode * root) {
    vector<int> res;
    if(!root)return res;
    dfs(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}