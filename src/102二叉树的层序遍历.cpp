#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：11.8 MB, 在所有 C++ 提交中击败了10.80% 的用户
//dfs即可，但是注意需要维护一个map来表示各节点所在层数
vector<vector<int>> levelOrder(TreeNode* root) {
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