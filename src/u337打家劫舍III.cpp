#include<bits/stdc++.h>
#include <TreeNode.hpp>
using namespace std;
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