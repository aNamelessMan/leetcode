#include "TreeNode.hpp"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void dfs(TreeNode *root, int &res, int &cur_num) {
    int v = root->val;
    cur_num = cur_num * 10 + v;
    if (root->left == nullptr && root->right == nullptr) {
      res += cur_num;
      return;
    }
    if (root->left != nullptr) {
      dfs(root->left, res, cur_num);
      cur_num /= 10;
    }
    if (root->right != nullptr) {
      dfs(root->right, res, cur_num);
      cur_num /= 10;
    }
  }
  int sumNumbers(TreeNode *root) {
    int res = 0;
    int cur_num = 0;
    dfs(root, res, cur_num);
    return res;
  }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：12.4 MB, 在所有 C++ 提交中击败了25.19% 的用户
int res = 0;
void dfs(TreeNode *root, int cur) {
  if (!root->left && !root->right) {
    res += (10 * cur + root->val);
    return;
  } else if (!root->left && root->right) {
    dfs(root->right, 10 * cur + root->val);
  } else if (!root->right && root->left) {
    dfs(root->left, 10 * cur + root->val);
  } else {
    dfs(root->left, 10 * cur + root->val);
    dfs(root->right, 10 * cur + root->val);
  }
}
int sumNumbers(TreeNode *root) {
  if (!root)
    return 0;
  dfs(root, 0);
  return res;
}

int main() { cout << 1 << endl; }