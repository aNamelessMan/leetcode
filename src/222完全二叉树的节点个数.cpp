#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了88.38% 的用户
// 内存消耗：30.7 MB, 在所有 C++ 提交中击败了41.30% 的用户
//用二分复杂度更低，下次再看吧
int countNodes(TreeNode* root) {
    if(!root)return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    cout << 1 << endl;
}