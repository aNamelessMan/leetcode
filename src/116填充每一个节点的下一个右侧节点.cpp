#include<bits/stdc++.h>
#include "Node.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了90.67% 的用户
// 内存消耗：17.1 MB, 在所有 C++ 提交中击败了23.85% 的用户
Node* connect(Node* root) {
    if(!root)return root;
    queue<Node*> q;
    q.push(root);
    int target = 1, cnt = 1;
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if(cnt == target){
            t->next = nullptr;
            cnt = 1;
            target *= 2;
        }else{
            t->next = q.front();
            cnt++;
        }

        if(t->left)q.push(t->left);
        if(t->right)q.push(t->right);
    }
    return root;
}

int main(){
    cout << 1 << endl;
}