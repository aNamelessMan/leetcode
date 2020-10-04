#include<bits/stdc++.h>
#include "TreeNode.hpp"
using namespace std;

map<unsigned, int> tail;
bool dfs(TreeNode* root, bool isEven, unsigned n){
    bool res = true;
    if(!root)return true;

    if(isEven){
        if((root->val) % 2 == 0)return false;
        if(tail.count(n))res = res && (root->val > tail[n]);
        tail[n] = root->val;
    }else{
        if((root->val) % 2 != 0)return false;
        if(tail.count(n))res = res && (root->val < tail[n]);
        tail[n] = root->val;
    }
    res = res && dfs(root->left, !isEven, n + 1);
    res = res && dfs(root->right, !isEven, n + 1);
    return res;
}

bool isEvenOddTree(TreeNode* root) {
    return dfs(root, true, 0);
}

int main(){
    cout << 1 << endl;
}