#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了93.45% 的用户
//套用前序遍历的代码，仅仅将左右子树入栈顺序颠倒，并将结果颠倒即可
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> res;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* t = stk.top();
        stk.pop();
        if(!t)continue;
        res.push_back(t->val);
        
        stk.push(t->left);
        stk.push(t->right);
    }
    reverse(res.begin(), res.end());
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：8.7 MB, 在所有 C++ 提交中击败了18.36% 的用户
void dfs(vector<int> &res, TreeNode* root){
    if(!root)return;
    dfs(res, root->left);
    dfs(res, root->right);
    res.push_back(root->val);
}

vector<int> recurpostorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(res, root);
    return res;
}

int main(){
    cout << 1 << endl;
}