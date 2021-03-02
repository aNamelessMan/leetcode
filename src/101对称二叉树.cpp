#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了84.86% 的用户
// 内存消耗：16 MB, 在所有 C++ 提交中击败了14.74% 的用户
//迭代法
bool iterisSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);//将根节点放入两次
    q.push(root);
    while(!q.empty()){
        TreeNode* u = q.front();
        q.pop();
        TreeNode* v = q.front();
        q.pop();
        if((u && !v) || (!u && v) || (u && v && u->val != v->val))return false;
        if(u){
            q.push(u->left);//将uv的左右节点按相反顺序放入
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }
    }
    return true;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了84.86% 的用户
// 内存消耗：15.9 MB, 在所有 C++ 提交中击败了25.96% 的用户
bool isfanzh(TreeNode* left, TreeNode* right){//判断左右子树是不是互为镜像
    if(!left && !right)return true;
    if((!left && right) || (left && !right) || (left->val != right->val))return false;
    return isfanzh(left->left, right->right) && isfanzh(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root)return true;
    return isfanzh(root->left, root->right);
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了12.82% 的用户
// 内存消耗：13.2 MB, 在所有 C++ 提交中击败了5.00% 的用户
//递归法，迭代法以后再说
//中序遍历后比较
void transfer(TreeNode *root, vector<int> &tree, int c, vector<int> &ceng){
    if(!root)return;
    transfer(root->left, tree, ++c, ceng);
    tree.push_back(root->val);ceng.push_back(--c);
    transfer(root->right, tree, ++c, ceng);
}

bool firstisSymmetric(TreeNode* root) {
    vector<int> tree;
    vector<int> ceng;
    transfer(root, tree, 0, ceng);
    int n = tree.size();
    for(int i = 0; i < n / 2; i++){
        if(tree[i] != tree[n - i - 1] || ceng[i] != ceng[n - i - 1])return false;
    }
    return true;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    iterisSymmetric(root);
    cout << 1 << endl;
}