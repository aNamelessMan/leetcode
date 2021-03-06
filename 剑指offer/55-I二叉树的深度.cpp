#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了64.62% 的用户
// 内存消耗：18.4 MB, 在所有 C++ 提交中击败了75.38% 的用户
int maxDepth(TreeNode* root) {
    if(!root)return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main(){
    cout << "print sth." << endl;
}