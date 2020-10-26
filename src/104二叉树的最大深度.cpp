#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了92.06% 的用户
// 内存消耗：16.8 MB, 在所有 C++ 提交中击败了28.96% 的用户
int maxi = 0;
void dfs(TreeNode* root, int i){
    if(!root)return;
    if(i > maxi)maxi = i;
    dfs(root->left, i + 1);
    dfs(root->right, i + 1);
}

int maxDepth(TreeNode* root) {
    dfs(root, 1);
    return maxi;
}

int main(){
    cout << 1 << endl;
}