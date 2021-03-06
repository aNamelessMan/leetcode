#include <bits/stdc++.h>
#include "../dataStruc/TreeNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了99.02% 的用户
// 内存消耗：23.6 MB, 在所有 C++ 提交中击败了59.44% 的用户
int kthLargest(TreeNode* root, int k) {
    //从大到小遍历，也就是把中序遍历两边颠倒一下
    stack<TreeNode*> stk;
    while(root || !stk.empty()){//root是当前要处理的节点，只有root和stk都为空才能退出
        while(root){
            stk.push(root);
            root = root->right;
        }

        root = stk.top();
        //以下两行可视为遍历中的process函数             本题只需要在中序遍历代码中加上这两行即可
        k--;
        if(k == 0)return root->val;

        stk.pop();
        
        root = root->left;
    }
    return -1;
}

int main(){
    cout << "print sth." << endl;
}