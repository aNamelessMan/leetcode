#include<bits/stdc++.h>
#include "../dataStruc/nodeWithRandom.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了52.10% 的用户
// 内存消耗：11.5 MB, 在所有 C++ 提交中击败了12.43% 的用户
Node* copyRandomList(Node* head) {
    unordered_map<Node*, int> idx2p1;//将原来的节点地址映射到索引
    Node* t = head;
    int cnt = 0;
    while(t){
        idx2p1[t] = cnt;
        cnt++;
        t = t->next;
    }
    //共有cnt个节点
    if(cnt == 0)return nullptr;

    unordered_map<int, Node*> idx2p2;//将索引映射到节点地址
    t = head;
    Node* res = new Node(t->val);
    Node* iter = res;
    int i = 0;
    idx2p2[i] = res;
    while(t->next){
        iter->next = new Node(t->next->val);
        t = t->next;
        iter = iter->next;
        idx2p2[++i] = iter;
    }
    iter->next = nullptr;

    t = head;
    iter = res;
    while(t){
        if(t->random == nullptr)iter->random = nullptr;//随机指针为空特殊处理，否则idx2p1[nullptr]会值初始化为0
        else iter->random = idx2p2[idx2p1[t->random]];
        t = t->next;
        iter = iter->next;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}