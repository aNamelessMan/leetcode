#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：9.5 MB, 在所有 C++ 提交中击败了5.21% 的用户
TreeNode* invertTree(TreeNode* root) {
    //后序遍历
    if(!root || (!root->left && !root->right))return root;
    else if(root->left && root->right){
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *t = root->left;
        root->left = root->right;
        root->right = t;
    }else if(root->left){
        invertTree(root->left);
        root->right = root->left;
        root->left = nullptr;
    }else{
        invertTree(root->right);
        root->left = root->right;
        root->right = nullptr;
    }
    return root;
}

int main(){
    cout << 1 << endl;
}