#include<bits/stdc++.h>
#include "../src/TreeNode.hpp"
using namespace std;

//您的提交打败了 73.40% 的提交!
void invertBinaryTree(TreeNode * root) {
    if(!root)return;
    TreeNode* t = root->left;
    root->left = root->right;
    root->right = t;
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

int main(){
    cout << 1 << endl;
}