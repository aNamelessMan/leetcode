#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：428 ms, 在所有 C++ 提交中击败了37.19% 的用户
// 内存消耗：141.8 MB, 在所有 C++ 提交中击败了29.17% 的用户
int minDepth(TreeNode* root) {
    if(!root)return 0;
    unordered_map<TreeNode*, int> floor;
    queue<TreeNode*>q;
    q.push(root);
    floor[root] = 1;
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(!t->left && !t->right)return floor[t];
        if(t->left){
            q.push(t->left);
            floor[t->left] =floor[t] + 1; 
        }
        if(t->right){
            q.push(t->right);
            floor[t->right] =floor[t] + 1; 
        }
    }
    return -1;
}

int main(){
    cout << 1 << endl;
}