#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了72.86% 的用户
// 内存消耗：17 MB, 在所有 C++ 提交中击败了12.73% 的用户
bool dfs(vector<TreeNode*> &path, int target, TreeNode* root){
    if(!root)return false;
    path.push_back(root);
    if(root->val == target){
        return true;
    }
    if(dfs(path, target, root->left))return true;//不加判断值大小也可以通过，加了是根据二叉树性质剪枝
    if(dfs(path, target, root->right))return true;
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p1, p2;
    dfs(p1, p->val, root);
    dfs(p2, q->val, root);
    int i = 0, s1 = p1.size(), s2 = p2.size();
    while(i < s1 && i < s2){
        if(p1[i] == p2[i])i++;
        else break;
    }
    return p1[i - 1];
}

int main(){
    cout << "print sth." << endl;
}