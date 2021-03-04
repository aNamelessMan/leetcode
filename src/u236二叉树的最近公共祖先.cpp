#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了92.55% 的用户
// 内存消耗：16.9 MB, 在所有 C++ 提交中击败了14.61% 的用户
//这个方法比下面一开始那个好理解多了
//先dfs获取根节点到两个节点的路径，然后逐个比较，返回最后一个相同的节点就是最近公共祖先，复杂度也是O(n)
bool dfs(vector<TreeNode*> &path, TreeNode* root, TreeNode* target){
    if(!root)return false;
    path.push_back(root);
    if(root == target)return true;
    if(dfs(path, root->left, target) || dfs(path, root->right, target)){
        return true;
    }
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> ppath;
    dfs(ppath, root, p);
    vector<TreeNode*> qpath;
    dfs(qpath, root, q);
    int n = min(ppath.size(), qpath.size());
    int i;
    for(i = 0; i < n; i++){//返回最后一个相等的父节点
        if(ppath[i] != qpath[i])break;
    }
    return ppath[i - 1];
}

// 执行用时：24 ms, 在所有 C++ 提交中击败了72.69% 的用户
// 内存消耗：14.5 MB, 在所有 C++ 提交中击败了20.27% 的用户
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//返回空代表不包含pq中任何一个，如果左右递归一个为空，一个不为空，
    //前序遍历
    if (!root || p == root || q == root) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p , q);
    if (left && right) return root;//左右都不为空，对应pq分别在左右子树
    return left ? left : right;//返回不为空的那个
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