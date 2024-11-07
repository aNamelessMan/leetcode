#include "TreeNode.hpp"
#include <bits/stdc++.h>
using namespace std;

/** 二叉树最容易想到的是递归，但这个解法是错的
 * 左子树和右子树都是二叉搜索树，且根节点在其左右子节点中间，不一定就是二叉搜索树
 * 其实用前序遍历看是不是严格从小到大即可
 */
bool wrongIsValidBST(TreeNode *root) {
  // base case
  if (root == nullptr)
    return true;
  if (root->left == nullptr && root->right == nullptr)
    return true;
  if (root->left != nullptr && root->val <= root->left->val)
    return false;
  if (root->right != nullptr && root->val >= root->right->val)
    return false;
  return isValidBST(root->left) && isValidBST(root->right);
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了88.95% 的用户
// 内存消耗：21.1 MB, 在所有 C++ 提交中击败了53.28% 的用户
// 中序遍历过程中判断是不是严格从小到大即可
bool isValidBST(TreeNode *root) {
  stack<TreeNode *> stk;
  long pre = (long)INT_MIN - 1;
  while (root || !stk.empty()) {
    while (root) {
      stk.push(root);
      root = root->left;
    }
    TreeNode *t = stk.top();
    stk.pop();

    if (t->val <= pre)
      return false;
    else
      pre = t->val;

    root = t->right;
  }
  return true;
}

// 执行用时：12 ms, 在所有 C++ 提交中击败了91.90% 的用户
// 内存消耗：18.2 MB, 在所有 C++ 提交中击败了16.77% 的用户
// 时间波动很大
// 注意需要验证左右子树下所有值小于/大于当前值
void maxdfs(TreeNode *root, int &m, bool maxormin) {
  if (!root)
    return;
  maxdfs(root->left, m, maxormin);
  if (maxormin && root->val > m)
    m = root->val;
  if (!maxormin && root->val < m)
    m = root->val;
  maxdfs(root->right, m, maxormin);
}

bool isValidBST(TreeNode *root) {
  int max = INT_MIN;
  int min = INT_MAX;
  if (!root)
    return true;
  if (root->left) {
    maxdfs(root->left, max, 1);
    if (max >= root->val)
      return false;
    max = INT_MIN;
  }
  if (root->right) {
    maxdfs(root->right, min, 0);
    if (min <= root->val)
      return false;
    min = INT_MAX;
  }
  return isValidBST(root->left) && isValidBST(root->right);
}

int main() { cout << 1 << endl; }