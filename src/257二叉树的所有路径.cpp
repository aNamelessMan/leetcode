#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了88.51% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了91.06% 的用户
void dfs(TreeNode* root, string cur, vector<string> &res){//root不会为空
    if(!root->left && !root->right){//若左右都为空
        res.push_back(cur + to_string(root->val));
        return;
    }
    if(root->left){
        dfs(root->left, cur + to_string(root->val) + "->", res);
    }
    if(root->right){
        dfs(root->right, cur + to_string(root->val) + "->", res);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root)
        dfs(root, "", res);
    return res;
}

int main(){
    cout << 1 << endl;
}