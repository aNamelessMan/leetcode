#include<bits/stdc++.h>
#include "../src/TreeNode.hpp"
using namespace std;

//您的提交打败了 6.20% 的提交!
void dfs(TreeNode * root, vector<int> &res){
    if(!root)return;
    res.push_back(root->val);
    dfs(root->left, res);
    dfs(root->right, res);
}
vector<int> preorderTraversal(TreeNode * root) {
    vector<int> res;
    if(!root)return res;
    dfs(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}