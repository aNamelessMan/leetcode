#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了83.02% 的用户
// 内存消耗：12.3 MB, 在所有 C++ 提交中击败了12.74% 的用户
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;    
    if(!root)return res;
    unordered_map<TreeNode*, int> m;//记录层数
    m[root] = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(!t)continue;
        if(m[t] == int(res.size())){
            res.push_back(vector<int>(1, t->val));
        }else{
            res[res.size() - 1].push_back(t->val);
        }
        q.push(t->left);
        q.push(t->right);
        m[t->left] = m[t] + 1;
        m[t->right] = m[t] + 1;
    }
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了10.80% 的用户
//dfs即可，但是注意需要维护一个map来表示各节点所在层数
vector<vector<int>> firstlevelOrder(TreeNode* root) {
    queue<TreeNode*> qt;
    unordered_map<TreeNode*, int> ceng;
    vector<vector<int>> res;
    if(root){
        qt.push(root);
        ceng.insert({root, 0});
    }
    int i = 0;
    while(!qt.empty()){
        TreeNode* t= qt.front();
        qt.pop();
        if(t){
            if(res.size() > ceng[t])
                res[ceng[t]].push_back(t->val);
            else{
                res.push_back({});
                res[ceng[t]].push_back(t->val);
            }
        }

        if(t->left){
            qt.push(t->left);
            ceng.insert({t->left, ceng[t] + 1});
        }
        if(t->right){
            qt.push(t->right);
            ceng.insert({t->right, ceng[t] + 1});
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}