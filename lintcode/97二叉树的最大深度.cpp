#include<bits/stdc++.h>
#include "../src/TreeNode.hpp"
using namespace std;

//您的提交打败了 100.00% 的提交!
int m = 0;
void dfs(TreeNode* root, int mt){
    if(!root)return;
    mt++;
    if(mt > m)m = mt;
    dfs(root->left, mt);
    dfs(root->right, mt);
}
int maxDepth(TreeNode * root) {
    if(!root)return m;
    dfs(root, 0);
    return m;
}

int main(){
    cout << 1 << endl;
}