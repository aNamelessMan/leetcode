#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了78.51% 的用户
// 内存消耗：11.9 MB, 在所有 C++ 提交中击败了59.37% 的用户
vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(t){
            res.push_back(t->val);
            q.push(t->left);
            q.push(t->right);
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}