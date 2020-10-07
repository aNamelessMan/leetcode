// 执行用时：4 ms, 在所有 C++ 提交中击败了64.92% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了96.75% 的用户
//每个节点只处理了一次，时间复杂度应该是最小了。。
 #include <bits/stdc++.h>
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 //把tmp定义成静态成员leetcode中会出错不知道为什么，但是本地没问题，百度后得知原因如下
 //https://support.leetcode-cn.com/hc/kb/article/1194344/
class Solution {
public:
//这是1038题的代码，只要改下函数名就是538的答案
    int tmp = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root != NULL){
            bstToGst(root->right);
            tmp += root->val;
            root->val = tmp;
            bstToGst(root->left);
        }
        return root;
    }
};
int main(){
    TreeNode r(0);
    TreeNode rr(1);
    r.right = &rr;

    Solution slt;
    TreeNode *s = slt.bstToGst(&r);
}