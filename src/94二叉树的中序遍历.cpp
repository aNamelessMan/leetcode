#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了6.91% 的用户
//递归解法，迭代解法以后再说吧
void inorder(TreeNode* node, vector<int> &res){
    if(!node)return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}