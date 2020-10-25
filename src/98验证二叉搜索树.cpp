#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了91.90% 的用户
// 内存消耗：18.2 MB, 在所有 C++ 提交中击败了16.77% 的用户
//时间波动很大
//注意需要验证左右子树下所有值小于/大于当前值
void maxdfs(TreeNode* root, int &m, bool maxormin){
    if(!root)return;
    maxdfs(root->left, m, maxormin);
    if(maxormin && root->val > m)m = root->val;
    if(!maxormin && root->val < m)m = root->val;
    maxdfs(root->right, m, maxormin);
}

bool isValidBST(TreeNode* root) {
    int max = INT_MIN;
    int min = INT_MAX;
    if(!root)return true;
    if(root->left){
        maxdfs(root->left, max, 1);
        if(max >= root->val)
            return false;
        max = INT_MIN;
    }
    if(root->right){
        maxdfs(root->right, min, 0);
        if(min <= root->val)
            return false;
        min = INT_MAX;
    }
    return isValidBST(root->left) && isValidBST(root->right);
}

int main(){
    cout << 1 << endl;
}