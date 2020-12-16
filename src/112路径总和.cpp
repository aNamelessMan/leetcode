#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了96.47% 的用户
// 内存消耗：17.6 MB, 在所有 C++ 提交中击败了26.70% 的用户
bool dfs(TreeNode* root, int cur, int target){
    if(!root)return false;
    cur += root->val;
    if(cur == target && !root->left && !root->right)return true;
    else{
        return dfs(root->left, cur, target) || dfs(root->right, cur, target);
    }
}

bool hasPathSum(TreeNode* root, int sum) {
    if(!root)return false;
    return dfs(root, 0, sum);
}

int main(){
    cout << 1 << endl;
}