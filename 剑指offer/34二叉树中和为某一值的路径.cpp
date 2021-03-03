#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.46% 的用户
// 内存消耗：19.2 MB, 在所有 C++ 提交中击败了93.36% 的用户
//注意要求是从根节点出发且必须结束于叶节点（也就是左右节点都为空的节点）
void dfs(vector<vector<int>> &res, vector<int> &path, int target, int cursum, TreeNode* root){
    path.push_back(root->val);
    cursum += root->val;

    if(!root->left && !root->right && cursum == target){
        res.push_back(path);//此处不能直接返回，否则path中当前节点未出栈
    }

    if(root->left)dfs(res, path, target, cursum, root->left);
    if(root->right)dfs(res, path, target, cursum, root->right);
    cursum -= root->val;
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if(!root)return res;
    vector<int> path;
    int cursum = 0;
    dfs(res, path, sum, cursum, root);
    return res;
}

int main(){
    cout << "print sth." << endl;
}