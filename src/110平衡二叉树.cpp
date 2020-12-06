#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了83.93% 的用户
// 内存消耗：21.8 MB, 在所有 C++ 提交中击败了5.09% 的用户
int geth(TreeNode* root, int cur){
    if(!root)return cur;
    else return max(geth(root->left, cur + 1), geth(root->right, cur + 1));
}

bool isBalanced(TreeNode* root) {
    if(!root)return true;
    int lh = geth(root->left, 0);
    int rh = geth(root->right, 0);

    if(abs(lh - rh) > 1)return false;
    return isBalanced(root->left) &&isBalanced(root->right);
}

int main(){
    cout << 1 << endl;
}