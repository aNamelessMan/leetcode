#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：36 ms, 在所有 C++ 提交中击败了61.08% 的用户
// 内存消耗：15.2 MB, 在所有 C++ 提交中击败了62.51% 的用户
//虽然自己写的过了但是还是有点糊
//双层dfs
void dfs(TreeNode* root, int target, int &res){
    if(!root)return;
    target -= root->val ;
    if(target == 0)res++;
    
    dfs(root->left, target, res);
    dfs(root->right, target, res);   
}
void basedfs(TreeNode* root, int sum, int &res){
    //basecase 处理从当前节点开始的和是否是sum
    if(!root)return;
    int target = sum - root->val ;
    if(target == 0)res++;
    dfs(root->left, target, res);
    dfs(root->right, target, res);

    basedfs(root->left, sum, res);//从左节点开始的和
    basedfs(root->right, sum, res);
}
int pathSum(TreeNode* root, int sum) {
    int res = 0;
    basedfs(root, sum, res);
    return res;
}

int main(){
    cout << 1 << endl;
}