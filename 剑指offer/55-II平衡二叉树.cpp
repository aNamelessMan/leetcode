#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了48.87% 的用户
// 内存消耗：24.7 MB, 在所有 C++ 提交中击败了5.04% 的用户
int maxdpt(TreeNode* root, unordered_map<TreeNode*, int> &depth){
    if(depth.find(root) != depth.end())return depth[root];
    int res = max(maxdpt(root->left, depth), maxdpt(root->right, depth)) + 1;
    depth[root] = res;
    return res;
}

bool dfs(TreeNode* root, unordered_map<TreeNode*, int> &m){
    if(!root)return true;
    if(abs(m[root->left] - m[root->right]) > 1)return false;
    return dfs(root->left, m) && dfs(root->right, m);
}

bool isBalanced(TreeNode* root) {
    unordered_map<TreeNode*, int> depth;
    depth[nullptr] = 0;
    maxdpt(root, depth);
    
    return dfs(root, depth);
}

int main(){
    cout << "print sth." << endl;
}