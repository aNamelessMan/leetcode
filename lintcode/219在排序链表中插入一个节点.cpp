#include<bits/stdc++.h>
#include "../src/ListNode.hpp"
using namespace std;

//您的提交打败了 100.00% 的提交!
ListNode * insertNode(ListNode * head, int val) {
    ListNode *res = head;
    ListNode *t = new ListNode(val);
    if(!head)return t;
    if(head->val > val){
        t->next = head;
        return t;
    }
    while(head->next && head->next->val < val)head = head->next;
    t->next = head->next;
    head->next = t;
    return res;
}

int main(){
    cout << 1 << endl;
}