#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了81.52% 的用户
// 内存消耗：16.2 MB, 在所有 C++ 提交中击败了35.27% 的用户
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return helper(1, n);
}
vector<TreeNode*> helper(int start, int end) {//返回由start到end节点组成的的所有可能的树
    if (start > end) return {nullptr};
    vector<TreeNode*> res;
    for (int i = start; i <= end; ++i) {
        auto left = helper(start, i - 1), right = helper(i + 1, end);
        for (auto a : left) {
            for (auto b : right) {
                TreeNode *node = new TreeNode(i);
                node->left = a;
                node->right = b;
                res.push_back(node);
            }
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}