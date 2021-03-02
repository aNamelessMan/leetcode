#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了98.61% 的用户
// 内存消耗：14.3 MB, 在所有 C++ 提交中击败了94.40% 的用户
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head, *iter = &head;
    while(l1 || l2){
        if(!l2 || (l1 && l1->val < l2->val)){
            iter->next = l1;
            l1 = l1->next;
        }else{
            iter->next = l2;
            l2 = l2->next;
        }
        iter = iter->next;
    }
    iter->next = nullptr;
    return head.next;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了85.39% 的用户
// 内存消耗：14.7 MB, 在所有 C++ 提交中击败了5.05% 的用户
//一次过了，就初始化第一个值有点麻烦
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1)return l2;
    if(!l2)return l1;
    ListNode* res = nullptr, *t = nullptr;
    if(l1->val < l2->val){
        res = new ListNode(l1->val);
        t = res;
        l1 = l1->next;
    }else{
        res = new ListNode(l2->val);
        t = res;
        l2 = l2->next;
    }
    while(l1 && l2){
        if(l1->val < l2->val){
            t->next = new ListNode(l1->val);
            t = t->next;
            l1 = l1->next;
        }else{
            t->next = new ListNode(l2->val);
            t = t->next;
            l2 = l2->next;
        }
    }
    if(l1)t->next = l1;
    else t->next = l2;
    return res;
}

int main(){
    cout << 1 << endl;
}