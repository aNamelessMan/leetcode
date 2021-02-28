#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：15.8 MB, 在所有 C++ 提交中击败了85.39% 的用户
//别人的写法，之前自己的写法是中序遍历后比较判断    LC101
bool isfanzh(TreeNode* a, TreeNode* b){
    //判断两颗二叉树是否互为对方的镜像
    if(!a && !b)return true;
    if((a && !b) || (!a && b) || (a->val != b->val))return false;
    return isfanzh(a->left, b->right) && isfanzh(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root)return true;
    return isfanzh(root->left, root->right);
}

int main(){
    cout << "print sth." << endl;
}