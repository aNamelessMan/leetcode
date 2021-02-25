#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了92.10% 的用户
/**2021.2.25三种遍历的迭代写法中，数前序遍历最容易理解。
递归思路：先树根，然后左子树，然后右子树。每棵子树递归。
 */
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> res;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* t = stk.top();
        stk.pop();
        if(!t)continue;
        res.push_back(t->val);
        
        stk.push(t->right);//注意栈是后进先出，因为遍历树时左子树在前，所以后入栈
        stk.push(t->left);
    }
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.2 MB, 在所有 C++ 提交中击败了75.32% 的用户
//递归解法，迭代解法有时间再看
void dfs(TreeNode* root, vector<int> &res){
    if(!root)return;
    res.push_back(root->val);
    dfs(root->left,res);
    dfs(root->right,res);
}

vector<int> recurpreorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}