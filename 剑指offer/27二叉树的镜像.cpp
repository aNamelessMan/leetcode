#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了98.09% 的用户
TreeNode* mirrorTree(TreeNode* root) {
    if(!root)return root;
    TreeNode* lt = mirrorTree(root->left);
    TreeNode* rt =mirrorTree(root->right);
    root->left = rt;
    root->right = lt;
    return root;
}

int main(){
    cout << "print sth." << endl;
}