#include<bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了82.05% 的用户
// 内存消耗：12.1 MB, 在所有 C++ 提交中击败了8.94% 的用户
vector<int> rightSideView(TreeNode* root) {
    //bfs按先右后左入列，每层只取第一个出现的值
    vector<int> res;
    if(!root)return res;
    queue<TreeNode*> q;
    unordered_map<TreeNode*, int> m;
    m[root] = 0;
    q.push(root);
    res.push_back(root->val);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(t->right){
            q.push(t->right);
            m[t->right] = m[t] + 1;
            if((int)res.size() == m[t->right])
                res.push_back(t->right->val);
        }
        if(t->left){
            q.push(t->left);
            m[t->left] = m[t] + 1;
            if((int)res.size() == m[t->left])
                res.push_back(t->left->val);
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}