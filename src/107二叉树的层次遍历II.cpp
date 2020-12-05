#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了90.45% 的用户
// 内存消耗：11.9 MB, 在所有 C++ 提交中击败了13.63% 的用户
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)return res;
    queue<TreeNode*> q;
    unordered_map<TreeNode*, int> m;
    q.push(root);
    m[root] = 0;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int cur = m[t];
        if(t->left){
            m[t->left] = cur + 1;
            q.push(t->left);
        }
        if(t->right){
            m[t->right] = cur + 1;
            q.push(t->right);
        }
        if((int)res.size() - 1 < cur){
            res.push_back({t->val});
        }else{
            res[cur].push_back(t->val);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << 1 << endl;
}