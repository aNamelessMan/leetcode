#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// 执行用时：64 ms, 在所有 C++ 提交中击败了10.31% 的用户
// 内存消耗：20.1 MB, 在所有 C++ 提交中击败了68.16% 的用户
//遍历每一个节点，求出左右子树深度之和，最大值即是最长路径
//注意最长路径不一定过根节点，因此不能简单取根节点左右子树深度相加，需要遍历
int height(TreeNode* root){
    int res = 0;
    if(!root)return 0;
    return 1 + max(height(root->left), height(root->right));
}
void upgradeM(TreeNode* root, int&m){
    if(!root)m =  max(m, 0);
    else    {
        m = max(m, height(root->left) + height(root->right));
        upgradeM(root->left, m);
        upgradeM(root->right, m);
    }
}
int diameterOfBinaryTree(TreeNode* root) {
    int m = 0;
    upgradeM(root, m);
    return m;
}
//可以建立节点到深度映射的哈希表，省去重复遍历
int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int res = getHeight(root->left) + getHeight(root->right);
    return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}
unordered_map<TreeNode*, int> m;
int getHeight(TreeNode* node) {
    if (!node) return 0;
    if (m.count(node)) return m[node];
    int h = 1 + max(getHeight(node->left), getHeight(node->right));
    return m[node] = h;
}
int main(){
    cout << 1 << endl;
}