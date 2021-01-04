#include<bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了98.01% 的用户
// 内存消耗：24.4 MB, 在所有 C++ 提交中击败了12.70% 的用户
//中序遍历就是从小到大顺序
void helper(TreeNode* root, vector<int> &tree, int k){
    if(!root || (int)tree.size() == k)return;//找到第k个后直接返回
    helper(root->left, tree, k);
    tree.push_back(root->val);
    helper(root->right, tree, k);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> tree;
    helper(root, tree, k);
    return tree[k - 1];
}

int main(){
    cout << 1 << endl;
}