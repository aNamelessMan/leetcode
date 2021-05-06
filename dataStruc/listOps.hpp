#ifndef LIST_OPS_HPP
#define LIST_OPS_HPP

#include <iostream>
#include <vector>
#include "ListNode.hpp"

ListNode* constructList(){
    ListNode res, *iter = &res;
    int x;

    while(std::cin >> x){
        if(x == -1)break;//用字符做结束符都会出错,服了
        iter->next = new ListNode(x);
        iter = iter->next;
    }

    return res.next;
}

ListNode* constructList(std::vector<int> &vi){
    ListNode *res = nullptr;
    
    int n = vi.size();
    if(n == 0)return res;

    res = new ListNode(vi[0]);
    ListNode *t = res;
    for(int i = 1; i < n; i++){
        t->next = new ListNode(vi[i]);
        t = t->next;
    }

    return res;
}

void printList(ListNode *r){
    if(!r)return;
    std::cout << r->val;
    r = r->next;
    while(r){
        std::cout << " -> " << r->val;
        r = r->next;
    }
    std::cout << std::endl;
}

#endif