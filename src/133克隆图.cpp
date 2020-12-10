#include<bits/stdc++.h>
#include "anotherNode.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了68.55% 的用户
// 内存消耗：9 MB, 在所有 C++ 提交中击败了31.88% 的用户
//bfs即可，写起来很麻烦
Node* cloneGraph(Node* node) {
    if(!node)return node;

    unordered_map<int, Node*> m;
    Node* res = new Node(node->val);
    m[node->val] = res;

    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if(m[t->val] == nullptr){
            m[t->val] = new Node(t->val);
        }
        if(m[t->val]->neighbors.size() != 0)continue;

        for(auto i = t->neighbors.begin(); i != t->neighbors.end(); i++){
            q.push(*i);
            Node* n;
            if(m[(*i)->val] == nullptr){
                n = new Node((*i)->val);
                m[(*i)->val] = n;
            }
            else n = m[(*i)->val];
            m[t->val]->neighbors.push_back(n);
        }

    }

    return res;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors.push_back(n2);n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);n4->neighbors.push_back(n3);

    //Node* res = cloneGraph(n1);

    cout << 1 << endl;
}