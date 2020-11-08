#include<bits/stdc++.h>
#include "../src/TreeNode.hpp"
using namespace std;

//您的提交打败了 100.00% 的提交!
void dfs(TreeNode* root, string p, vector<string> &res){
    p += '-';
    p += '>';
    p += to_string(root->val);
    if(!root->left && !root->right){
        res.push_back(p);
        return;
    }
    if(root->left)dfs(root->left, p, res);
    if(root->right)dfs(root->right, p, res);
}

vector<string> binaryTreePaths(TreeNode * root) {
    vector<string> res;
    if(!root)return res;
    string p;
    p += to_string(root->val);
    if(!root->left && !root->right)res.push_back(p);
    if(root->left)dfs(root->left, p, res);
    if(root->right)dfs(root->right, p, res);
}

int main(){
    cout << 1 << endl;
}