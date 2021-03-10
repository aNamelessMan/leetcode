#include<bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了61.82% 的用户
// 内存消耗：27.9 MB, 在所有 C++ 提交中击败了38.43% 的用户
//2021.3.10自己的写法，就是暴力dfs加上hash表保存已计算结果，防止重复计算
int dfs(TreeNode* root, unordered_map<TreeNode*, int> &rob, unordered_map<TreeNode*, int> &nrob, bool canst){//返回
    if(!root)return 0;

    int st = 0;
    if(canst){
        if(rob.find(root) != rob.end()){
            st = rob[root];
        }else{
            st = dfs(root->left, rob, nrob, false) + dfs(root->right, rob, nrob, false) + root->val;
            rob[root] = st;
        }
    }
    int nst = 0;
    if(nrob.find(root) != nrob.end()){
        nst = nrob[root];
    }else{
        nst = dfs(root->left, rob, nrob, true) + dfs(root->right, rob, nrob, true);
        nrob[root] = nst;
    }
    return max(st, nst);
}

int rob(TreeNode* root) {
    int res = 0;
    unordered_map<TreeNode*, int> rob, nrob;//记录在偷/不偷该节点的情况下 由该节点往下所得到的最大收获
    return dfs(root, rob, nrob, true);
}

// 执行用时：24 ms, 在所有 C++ 提交中击败了81.04% 的用户
// 内存消耗：25.1 MB, 在所有 C++ 提交中击败了53.33% 的用户
//递归即可  dfs返回该节点可以偷时的最大值
int dfs(TreeNode* root, unordered_map<TreeNode*, int> &calced){//注意这里的root可以偷
    if(!root)return 0;
    if(calced.count(root))return calced[root];
    int v = 0;
    if(root->left){
        v += dfs(root->left->left, calced) + dfs(root->left->right, calced);
    }
    if(root->right){
        v += dfs(root->right->left, calced) + dfs(root->right->right, calced);
    }
    v = max(v + root->val, dfs(root->left, calced) + dfs(root->right, calced));//max(偷当前节点，不偷当前节点)
    calced[root] = v;
    return v;
}

int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> calced;//保存计算过的节点防止重复计算，作用等于之前198题里的dp数组
    return dfs(root, calced);
}

int main(){
    cout << 1 << endl;
}