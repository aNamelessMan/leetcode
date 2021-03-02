#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：300 ms, 在所有 C++ 提交中击败了83.27% 的用户
// 内存消耗：141.2 MB, 在所有 C++ 提交中击败了68.62% 的用户
int minDepth(TreeNode* root) {
    if(!root)return 0;//只是为了处理输入为空的情况，递归时root不会为空
    if(!root->left && !root->right)return 1;//注意只有到达左右节点皆为空的节点才能计算深度
    else if(!root->left && root->right) return minDepth(root->right) + 1;
    else if(root->left && !root->right) return minDepth(root->left) + 1;
    else
        return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// 执行用时：428 ms, 在所有 C++ 提交中击败了37.19% 的用户
// 内存消耗：141.8 MB, 在所有 C++ 提交中击败了29.17% 的用户
int firstminDepth(TreeNode* root) {
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