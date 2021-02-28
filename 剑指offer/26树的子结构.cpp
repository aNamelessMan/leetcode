#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：88 ms, 在所有 C++ 提交中击败了7.25% 的用户
// 内存消耗：74 MB, 在所有 C++ 提交中击败了5.01% 的用户
//暴力解法，比较 B 是不是 从每个节点开始的子树 的一部分
bool dfs(TreeNode* root, vector<TreeNode*> &btree, int n){
    if(!root)return false;
    int i = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty() && i < n){
        TreeNode* t = q.front();
        q.pop();
        if(!btree[i]){
            i++;
            continue;
        }else if(!t){
            break;
        }else if(btree[i]->val != t->val){
            break;
        }else{
            if(t){
                q.push(t->left);
                q.push(t->right);
            }
            i++;
        }
    }
    if(i == n) return true;
    else return dfs(root->left, btree, n) || dfs(root->right, btree, n);
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(!A || !B)return false;
    //bfs B树
    vector<TreeNode*> btree;
    queue<TreeNode*> q;
    q.push(B);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        btree.push_back(t);
        if(t){
            q.push(t->left);
            q.push(t->right);
        }
    }
    int n = btree.size();
    return dfs(A, btree, n);
}

int main(){
    cout << "print sth." << endl;
}