#include <bits/stdc++.h>
#include "../dataStruc/nodeWithRandom.hpp"
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了75.72% 的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了22.84% 的用户
Node* copyRandomList(Node* head) {
    unordered_map<Node*, int> idx;//记录每个节点在链表1中的下标
    unordered_map<int, Node*> nodes;//记录每个下标在链表2中对应的节点
    //设置nullptr的映射，否则会默认为0
    idx[nullptr] = -1;
    nodes[-1] = nullptr;

    int i = 0;
    Node h(0);
    Node* iter1 = head, *iter2 = &h;
    while(iter1){
        iter2->next = new Node(iter1->val);
        nodes[i] = iter2->next;
        iter2 = iter2->next;

        idx[iter1] = i;
        iter1 = iter1->next;

        i++;
    }
    iter2 = h.next, iter1 = head;
    i = 0;
    while(iter2){
        iter2->random = nodes[idx[iter1->random]];
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    return h.next;
}

int main(){
    cout << "print sth." << endl;
}