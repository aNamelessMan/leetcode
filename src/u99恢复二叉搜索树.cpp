#include<bits/stdc++.h>
#include <../dataStruc/TreeNode.hpp>
using namespace std;

// 执行用时：40 ms, 在所有 C++ 提交中击败了89.90% 的用户
// 内存消耗：58.1 MB, 在所有 C++ 提交中击败了15.28% 的用户
//O(N)空间的解法，常数级的以后再说吧
void inorder(TreeNode* root, vector<TreeNode*> &treen, vector<int> &treev){
    if(!root)return;
    inorder(root->left, treen, treev);
    treen.push_back(root);
    treev.push_back(root->val);
    inorder(root->right, treen, treev);
}

void recoverTree(TreeNode* root) {
    //中序遍历二叉树，并将节点和值分别存到数组中
    vector<TreeNode*> treen;
    vector<int> treev;
    inorder(root, treen, treev);
    sort(treev.begin(), treev.end());

    int n = treev.size();
    for(int i = 0; i < n; i++){
        treen[i]->val = treev[i];
    }
}

int main(){
    cout << 1 << endl;
}