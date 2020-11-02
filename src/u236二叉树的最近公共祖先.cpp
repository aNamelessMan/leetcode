#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：24 ms, 在所有 C++ 提交中击败了72.69% 的用户
// 内存消耗：14.5 MB, 在所有 C++ 提交中击败了20.27% 的用户
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //前序遍历
    if (!root || p == root || q == root) return root;//root为空对应不是公共祖先
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p , q);
    if (left && right) return root;//左右都不为空，对应pq分别在左右子树
    return left ? left : right;
}

//暴力解法TLE 29 / 31 个通过测试用例
bool ispubAnseter(TreeNode* root, int p, int q){//判断root是否是pq的公共祖先
    if(!root)return false;
    bool ispin = false;
    bool isqin = false;
    queue<TreeNode*> qq;
    qq.push(root);
    TreeNode *t = nullptr;
    while(!qq.empty()){
        t = qq.front();
        qq.pop();
        if(t->val == p)ispin = true;
        if(t->val == q)isqin = true;
        if(t->left)qq.push(t->left);
        if(t->right)qq.push(t->right);
    }
    return ispin && isqin;
}
TreeNode* BFlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//最近公共祖先xx节点的子节点同时包含p和q，并且需要尽可能深
//尽可能深可以通过左右子节点都不是公共祖先来确定
//且左右子节点只可能有一个是公共祖先
//且lowstCommonAncestor的输入root一定是公共祖先
    int vp = p->val, vq = q->val;
    bool isl = ispubAnseter(root->left, vp, vq), isr = ispubAnseter(root->right, vp, vq);
    if(!isl && !isr)return root;
    else if(isl)return BFlowestCommonAncestor(root->left, p, q);
    else    return BFlowestCommonAncestor(root->right, p, q);
}

int main(){
    cout << 1 << endl;
}