#include<bits/stdc++.h>
#include "Node.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了45.29% 的用户
// 内存消耗：19 MB, 在所有 C++ 提交中击败了5.02% 的用户
Node* connect(Node* root) {
    if(!root)return root;
    queue<Node*> q;
    unordered_map<Node*, int> floor;
    q.push(root);
    floor[root] = 1;
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if(q.empty() || floor[q.front()] != floor[t]){
            t->next = nullptr;
        }else{
            t->next = q.front();
        }

        if(t->left){
            q.push(t->left);
            floor[t->left] = floor[t] + 1;
        }
        if(t->right){
            q.push(t->right);
            floor[t->right] = floor[t] + 1;
        }
    }
    return root;
}

int main(){
    cout << 1 << endl;
}