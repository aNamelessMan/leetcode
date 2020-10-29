#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

ListNode* merge(ListNode* h1, ListNode* h2){//归并两个有序链表即可
    if(!h1)return h2;
    if(!h2)return h1;
    ListNode* r = nullptr;
    if(h1->val < h2->val){
        r = new ListNode(h1->val);
        h1 = h1->next;
    }else{
        r = new ListNode(h2->val);
        h2 = h2->next;
    }
    ListNode* res = r;
    while(h1 && h2){
        if(h1->val < h2->val){
            r->next = new ListNode(h1->val);
            h1 = h1->next;
        }else{
            r->next = new ListNode(h2->val);
            h2 = h2->next;
        }
        r = r->next;
    }
    if(h1)r->next = h1;
    if(h2)r->next = h2;
    return res;
}

ListNode* sortList(ListNode* head) {//sortList函数返回有序链表的头指针，因此可以用归并排序递归解决
    if(!head || !head->next)return head;
    ListNode* slow = head, *fast = head, *pre = head;
    while(fast && fast->next){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;//注意断开
    return merge(sortList(head), sortList(slow));
}

int main(){
    cout << 1 << endl;
}