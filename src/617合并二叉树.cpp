#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 执行用时：76 ms, 在所有 C++ 提交中击败了66.82% 的用户
// 内存消耗：32.9 MB, 在所有 C++ 提交中击败了20.65% 的用户
//递归解法
TreeNode* merge(TreeNode* t1, TreeNode* t2, TreeNode* root){
    if(!t2 && !t1)root = nullptr;
    else if(t1 && !t2)root = t1;
    else if(!t1 && t2)root = t2;
    else{
        root = new TreeNode(t1->val + t2->val);
        root->left = merge(t1->left, t2->left, root->left);
        root->right = merge(t1->right, t2->right, root->right);
    }
    return root;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* root = new TreeNode(0);
    if(!t1 && !t2)return nullptr;
    return merge(t1, t2, root);
}

int main(){
    cout << 1 << endl;
}