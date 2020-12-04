#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

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