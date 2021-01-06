#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：44 ms, 在所有 C++ 提交中击败了47.27% 的用户
// 内存消耗：23.3 MB, 在所有 C++ 提交中击败了36.27% 的用户
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //二叉搜索树的根节点值处于左右节点值之间
    if(!root)return nullptr;
    else if(root->val > max(p->val, q->val)){//大于两者的较大值，继续尝试左节点
        return lowestCommonAncestor(root->left, p, q);
    }else if(root->val < min(p->val, q->val)){
        return lowestCommonAncestor(root->right, p, q);
    }else{//root->val在[p, q]中
        return root;
    }
}

int main(){
    cout << 1 << endl;
}