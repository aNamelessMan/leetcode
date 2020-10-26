#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了95.97% 的用户
// 内存消耗：12.7 MB, 在所有 C++ 提交中击败了5.28% 的用户
//自己的写法，写的很繁琐...
TreeNode* dfs(TreeNode* root){
    if(!root)return nullptr;
    if(!root->left && !root->right){
        return root;
    }else if(root->right && root->left){
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        TreeNode *lt = dfs(root->left);
        TreeNode *rt = dfs(root->right);
        root->right = l;
        root->left = nullptr;//注意转换完一定要将左指针置为空才算完成，否则会出错，
        lt->right = r;
        return rt;
    }else if(root->right){
        TreeNode *rt = dfs(root->right);
        return rt;
    }else{
        TreeNode *l = root->left;
        TreeNode *lt = dfs(root->left);
        root->right = l;
        root->left = nullptr;//！！！！！！！！！！！！！
        return lt;
    }
}

void flatten(TreeNode* root) {
    dfs(root);
}

int main(){
    cout << 1 << endl;
}