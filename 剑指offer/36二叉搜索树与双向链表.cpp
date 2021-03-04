#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 执行用时：8 ms, 在所有 C++ 提交中击败了71.79% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了31.04% 的用户
void inorder(vector<Node*> &s, Node* root){
    if(!root)return;
    inorder(s, root->left);
    s.push_back(root);
    inorder(s, root->right);
}

Node* treeToDoublyList(Node* root) {
    if(!root)return root;
    vector<Node*> s;
    inorder(s, root);

    int n = s.size();
    s[0]->left = s.back();
    s[0]->right = n > 1?s[1]:s[0];
    s[n - 1]->right = s[0];
    s[n - 1]->left = n > 1?s[n - 2]:s[0];

    for(int i = 1; i < n - 1; i++){
        s[i]->left = s[i - 1];
        s[i]->right = s[i + 1];
    }
    return s[0];
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    treeToDoublyList(root);
    cout << "print sth." << endl;
}