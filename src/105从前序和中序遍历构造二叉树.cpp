#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

// 执行用时：28 ms, 在所有 C++ 提交中击败了55.89% 的用户
// 内存消耗：25.1 MB, 在所有 C++ 提交中击败了40.40% 的用户
/*
2021.2.15二刷自己写的解法
画个图看一下就很简单，递归参数需要前序中序遍历序列在数组中的位置

可以重建的必要条件是没有重复值，因为重建是需要根据根节点元素值来划分
而且不可以从前序和后序遍历来重建，因为这两种遍历无法区分左右节点的相对先后
*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pl, int ph, int il, int ih){
    /*
    pl ph是需要重建的这段的前序遍历在preorder中的范围
    il ih是需要重建的这段的中序遍历在inorder中的范围
    均为前闭后闭
    */
    if(pl > ph)return nullptr;
    int root = preorder[pl];
    TreeNode* res = new TreeNode(root);

    int i = il;
    for(; i <= ih; i++){
        if(inorder[i] == root)break;
    }
    int lil = il, lih = i - 1, ril = i + 1, rih = i == ih?ih - 1:ih;//为了防止i == ih时将节点i重复计算
    int lpl = pl + 1, lph = lpl + i - 1 - il, rpl = lph + 1, rph = rpl + rih - ril;//这一行只需要知道序列起点，再确保与上面的长度即可，也就是用起点加上上面的差
    res->left = buildTree(preorder, inorder, lpl, lph, lil, lih);
    res->right = buildTree(preorder, inorder, rpl, rph, ril, rih);
    return res;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
}

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

TreeNode* firstbuildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* res = dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return res;
}

int main(){
    cout << 1 << endl;
}