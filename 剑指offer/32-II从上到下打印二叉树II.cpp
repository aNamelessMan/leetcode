#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：12.1 MB, 在所有 C++ 提交中击败了91.19% 的用户
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if(root)q.push(root);
    while(!q.empty()){
        int n = q.size();
        res.push_back(vector<int>());
        for(int i = 0; i < n; i++){
            TreeNode* t = q.front();
            q.pop();
            res.back().push_back(t->val);
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}