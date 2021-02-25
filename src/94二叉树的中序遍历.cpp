#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了63.14% 的用户
/*
栈S;
p= root;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    p = S.top 出栈;
    访问p;
    p = p的右子树;
}
*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while(root || !stk.empty()){
        while(root){
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);       //中序遍历是左中右，因此只有当没有左节点时才可以访问当前节点，访问完后应该处理右节点
        root = root->right;
    }
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了6.91% 的用户
//递归解法，迭代解法以后再说吧
void inorder(TreeNode* node, vector<int> &res){
    if(!node)return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
}
vector<int> recurinorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}