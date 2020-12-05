#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：44 ms, 在所有 C++ 提交中击败了39.80% 的用户
// 内存消耗：17.4 MB, 在所有 C++ 提交中击败了49.29% 的用户
TreeNode* buildTree(vector<int>& inorder, int ins, int ine, vector<int>& postorder, int pos, int poe) {
    if(ins > ine || pos > poe)return nullptr;
    else if(ins == ine && pos == poe){
        TreeNode *root = new TreeNode(inorder[ins]);
        return root;
    }else{
        TreeNode *root = new TreeNode(postorder[poe]);
        int i;
        for(i = ins; i <= ine; i++){
            if(inorder[i] == postorder[poe])break;
        }
        int lcnt = i - ins;
        int rcnt = ine - i;
        root->left = buildTree(inorder, ins, i - 1, postorder, pos, pos + i - ins - 1);
        root->right = buildTree(inorder, i + 1, ine, postorder, pos + i - ins, poe - 1);
        return root;
    }

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    return buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
}

int main(){
    cout << 1 << endl;
}