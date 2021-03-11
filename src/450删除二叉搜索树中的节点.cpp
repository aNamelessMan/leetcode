#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：40 ms, 在所有 C++ 提交中击败了83.95% 的用户
// 内存消耗：31.7 MB, 在所有 C++ 提交中击败了97.29% 的用户
//错了好多次
//主要每调整一个节点，都要考虑他的上下节点放在哪
TreeNode* findrmin(TreeNode* pre, TreeNode* cur){
    bool l = false;
    while(cur && cur->left){
        if(l)pre = pre->left;
        else pre = pre->right;
        cur = cur->left;
        l = true;
    }
    if(l){
        pre->left = cur->right;
    }
    else pre->right = cur->right;
    return cur;
}

TreeNode* findlmax(TreeNode* pre, TreeNode* cur){
    bool l = true;
    while(cur && cur->right){
        if(l)pre = pre->left;
        else pre = pre->right;
        cur = cur->right;
        l = false;
    }
    if(l){
        pre->left = cur->left;
    }
    else pre->right = cur->left;
    return cur;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode vnode, *pre = &vnode, *iter = root;
    vnode.left = root;
    bool l = true;
    while(iter && iter->val != key){
        if(l)pre = pre->left;
        else pre = pre->right;
        if(iter->val < key){
            iter = iter->right;
            l = false;
        }else{
            iter = iter->left;
            l = true;
        }
    }
    if(!iter)return root;
    TreeNode *candidate;
    if(iter->right){
        candidate = findrmin(iter, iter->right);
    }else if(iter->left){
        candidate = findlmax(iter, iter->left);
    }else{
        candidate = nullptr;
    }
    if(l)pre->left = candidate;
    else pre->right = candidate;
    if(candidate){
        candidate->left = iter->left;
        candidate->right = iter->right;
    }
    return vnode.left;
}

int main(){
    cout << "print sth." << endl;
}