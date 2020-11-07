#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：44 ms, 在所有 C++ 提交中击败了77.72% 的用户
// 内存消耗：28.5 MB, 在所有 C++ 提交中击败了5.03% 的用户
int helper(TreeNode *root, int &res){//返回以当前结点为根结点，到叶节点的最大路径之和
    if(!root)return 0;
    int left = max(helper(root->left, res), 0);
    int right = max(helper(root->right, res), 0);
    res = max(res, root->val + left + right);
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}