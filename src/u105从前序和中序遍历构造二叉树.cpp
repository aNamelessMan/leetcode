#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;
// 执行用时：56 ms, 在所有 C++ 提交中击败了25.60% 的用户
// 内存消耗：17.3 MB, 在所有 C++ 提交中击败了54.67% 的用户
//思路很简单，具体写起来比较麻烦，就是从前序遍历中确定根节点，然后根据根节点在中序遍历中确定左右子树，最后递归
//麻烦的地方在于确定下标
TreeNode* dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
    if(il > ir || pl > pr)return nullptr;
    int i;
    for(i = 0; i <= ir; i++){//前序遍历的第一个肯定是根节点
        if(preorder[pl] == inorder[i])break;//i是根节点在中序里的位置
        //i - il是左子树的元素个数  因此下一次递归时左子树前序的范围为[pl + 1, pl + i - il]，右子树范围为[pl + i - il + 1. pr]
        //中序遍历的下标就是按i左右分割即可
    }
    TreeNode *res = new TreeNode(preorder[pl]);
    res->left = dfs(preorder, pl + 1, pl + i - il, inorder, il, i - 1);
    res->right = dfs(preorder, pl + i - il + 1, pr, inorder, i + 1, ir);
    return res;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* res = dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return res;
}

int main(){
    cout << 1 << endl;
}