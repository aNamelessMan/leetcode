#ifndef LIST_OPS_HPP
#define LIST_OPS_HPP

#include <iostream>
#include <vector>
#include "ListNode.hpp"

ListNode* constructList(){
    ListNode *res = nullptr;
    ListNode* t = nullptr;
    int x;
    if(std::cin >> x){
        res = new ListNode(x);
        t = res;
    }
    while(std::cin >> x){
        t->next = new ListNode(x);
        t = t->next;
    }
    return res;
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
    while(r){
        std::cout << r->val << ",";
        r = r->next;
    }
    std::cout << std::endl;
}

#endif