#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了75.38% 的用户
// 内存消耗：24.4 MB, 在所有 C++ 提交中击败了90.10% 的用户
TreeNode* reconstruct(vector<int>& preorder, vector<int>& inorder, int pl, int ph, int il, int ih){
    if(pl > ph || il > ih){
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[pl]);
    int i;
    for(i = il; i <= ih; i++){
        if(inorder[i] == preorder[pl])break;
    }
    int lil = il, lih = i - 1, ril = i + 1, rih = ih;
    int lpl = pl + 1, lph = lpl + lih - lil, rpl = lph + 1, rph = rpl + rih - ril;//这一行只需要知道序列起点，再确保与上面的长度即可，也就是用起点加上上面的差
    root->left = reconstruct(preorder, inorder, lpl, lph, lil, lih);
    root->right = reconstruct(preorder, inorder, rpl, rph, ril, rih);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    return reconstruct(preorder, inorder, 0, n - 1, 0, n - 1);
}

int main(){
    cout << "print sth." << endl;
}