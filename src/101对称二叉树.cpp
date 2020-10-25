#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了12.82% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了5.00% 的用户
//递归法，迭代法以后再说
void transfer(TreeNode *root, vector<int> &tree, int c, vector<int> &ceng){
    if(!root)return;
    transfer(root->left, tree, ++c, ceng);
    tree.push_back(root->val);ceng.push_back(--c);
    transfer(root->right, tree, ++c, ceng);
}

bool isSymmetric(TreeNode* root) {
    vector<int> tree;
    vector<int> ceng;
    transfer(root, tree, 0, ceng);
    int n = tree.size();
    for(int i = 0; i < n / 2; i++){
        if(tree[i] != tree[n - i - 1] || ceng[i] != ceng[n - i - 1])return false;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}