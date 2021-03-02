#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了65.00% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了11.41% 的用户
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)return res;
    bool rev = false;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int cengsize = q.size();
        res.push_back(vector<int>());
        for(int i = 0; i < cengsize; i++){
            TreeNode* t = q.front();
            q.pop();
            res.back().push_back(t->val);
            if(t->left)q.push(t->left);//注意不能改变入队顺序
            if(t->right)q.push(t->right);
        }
        if(rev){
            reverse(res.back().begin(), res.back().end());
        }
        rev = !rev;
    }
    return res;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了74.77% 的用户
// 内存消耗：12.1 MB, 在所有 C++ 提交中击败了5.02% 的用户
void bfs(vector<vector<int>> &res, vector<TreeNode*> curfloor, int turn){
    vector<int> tmp;
    vector<TreeNode*> nextfloor;
    bool vaild = false;
    for(auto &r:curfloor){
        if(r){
            vaild = true;
            tmp.push_back(r->val);
            nextfloor.push_back(r->left);
            nextfloor.push_back(r->right);
        }
    }
    if(!vaild)return;
    if(turn)reverse(tmp.begin(), tmp.end());
    res.push_back(tmp);
    bfs(res, nextfloor, !turn);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    vector<TreeNode*> curfloor;
    curfloor.push_back(root);
    bfs(res, curfloor, false);
    return res;
}

int main(){
    cout << 1 << endl;
}