#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了94.51% 的用户
// 内存消耗：27.8 MB, 在所有 C++ 提交中击败了36.11% 的用户
//2021.3.13日自己的解法，比之前简洁
int dfs(TreeNode* root, int &res){//返回由这个节点出发能到达的最大值    注意在遍历过程中更新res
    if(!root->left && !root->right){
        res = max(res, root->val);
        return root->val;
    }
    int l = root->left?max(dfs(root->left, res), 0):0, r = root->right?max(dfs(root->right, res), 0):0;
    res = max({res, root->val + l + r});
    return root->val + max(l, r);
}

int maxPathSum(TreeNode* root) {
    if(!root)return 0;
    int res = INT_MIN;
    dfs(root, res);
    return res;
}

// 执行用时：72 ms, 在所有 C++ 提交中击败了5.93% 的用户
// 内存消耗：37.9 MB, 在所有 C++ 提交中击败了5.18% 的用户
//2021.2.21日二刷自己写的解法 复杂度O(n)
void process(TreeNode* root, unordered_map<TreeNode*, int> &sum, unordered_map<TreeNode*, int> &processed){//填充process数组，包含该节点在内的最大左/右子路径
    if(!processed[root->left]){
        process(root->left, sum, processed);
    }
    if(!processed[root->right]){
        process(root->right, sum, processed);
    }
    sum[root] = root->val + max({0, sum[root->left], sum[root->right]});
    processed[root] = 1;
}

void dfs(TreeNode* root, int &res, unordered_map<TreeNode*, int> &sum){//返回经过此节点的最大路径
    if(root){
        res = max({res, root->val, root->val + sum[root->left], root->val + sum[root->right], root->val + sum[root->left] + sum[root->right]});
        dfs(root->left, res, sum);
        dfs(root->right, res, sum);
    }
}
//可以把dfs函数合并到process函数中，只要加上res参数，并在函数末尾加上更新res这一步即可，但是实测速度变慢了...

int maxPathSum(TreeNode* root) {
    //经过某节点的最大路径和，就是左子路径的最大值 + 右子路径的最大值 + 节点值，左右子路径值最小为0
    //左/右子路径的最大值为   当前节点值 + 该节点的左右子路径最大值
    unordered_map<TreeNode*, int> sum, processed;//分别表示子路径最大值，机该节点是否处理过
    sum[nullptr] = 0;
    processed[nullptr] = 1;
    process(root, sum, processed);

    int res = INT_MIN;
    dfs(root, res, sum);
    return res;
}

// 执行用时：44 ms, 在所有 C++ 提交中击败了77.72% 的用户
// 内存消耗：28.5 MB, 在所有 C++ 提交中击败了5.03% 的用户
int helper(TreeNode *root, int &res){//返回以当前结点为根结点，到叶节点的最大路径之和
    if(!root)return 0;
    int left = max(helper(root->left, res), 0);
    int right = max(helper(root->right, res), 0);
    res = max(res, root->val + left + right);
    return max(left, right) + root->val;
}

int firstmaxPathSum(TreeNode* root) {
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main(){
    cout << 1 << endl;
}