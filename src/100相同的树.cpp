#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：10.2 MB, 在所有 C++ 提交中击败了26.01% 的用户
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr)return true;
    if(p && q && p->val == q->val)return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}

int main(){
    cout << 1 << endl;
}