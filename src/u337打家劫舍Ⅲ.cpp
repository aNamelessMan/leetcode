#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

//理解错题目意思了，偷了当前节点不代表一定也要偷孙子节点
//例如4->1->2->3的结果是7
int dfs(TreeNode* root, bool r){
    if(!root)return 0;
    if(r)return root->val + dfs(root->left, !r) + dfs(root->right, !r);
    else return dfs(root->left, !r) + dfs(root->right, !r);
}

int wrongrob(TreeNode* root) {
    //可以分为包含根节点和不包含根节点两种情况分别dfs找出最大值
    int r1 = dfs(root, true);//包含根节点的情况
    int r2 = dfs(root, false);//不包含
    return max(r1, r2);
}

int main(){
    cout << 1 << endl;
}