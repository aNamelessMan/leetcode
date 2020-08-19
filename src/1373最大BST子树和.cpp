 #include <bits/stdc++.h>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  /*
  首先判断子树是不是BST，返回最大和
  以TreeNode* root为根节点的树是不是BST需要判断以下四点：
  1.  左子树是不是BST
  2.  右子树是不是BST
  3.  根节点值是不是大于左子树中的最大值
  3.  根节点值是不是小于右子树中的最小值
  为了判断需要用一个vector存下该根节点【是否为BST、最小值、最大值、和值】
  因为判断需要根节点需要先判断左右子树，所以后序遍历
  遍历时更新vector和maxsum即可
*/
class Solution {
public:
int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }

    std::vector<int> dfs(TreeNode* root){
        if(!root)return {true, INT_MAX, INT_MIN, 0};
        auto lres = dfs(root->left);
        auto rres = dfs(root->right);
        int sum = 0, curmax, curmin;
        if(lres[0] && rres[0] && root->val > lres[2] && root->val < rres[1]){
            curmin = root->left ? lres[1] : root->val;
            curmax = root->right ? rres[2] : root->val;
            sum += (root->val + lres[3] + rres[3]);
            maxsum = std::max(maxsum, sum);
            return {true, curmin, curmax, sum};
        }
        return {false, 0, 0, 0};
    }
};