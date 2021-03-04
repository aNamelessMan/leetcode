#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了43.57% 的用户
//2021.3.4二刷  严格的一次遍历
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode h, *hp = &h;
    h.next = head;
    int i = 1;
    while(i < left){
        hp = hp->next;
        i++;
    }
    //此时hp指向翻转链表的前一个节点
    ListNode* reversed = nullptr, *iter = hp->next, *next, *prev = hp->next;//prev指向要翻转的第一个节点，也就是翻转后的最后一个的节点
    while(i < right + 1){
        next = iter->next;
        iter->next = reversed;
        reversed = iter;
        iter = next;
        i++;
    }
    hp->next = reversed;
    prev->next = iter;
    return h.next;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7 MB, 在所有 C++ 提交中击败了5.03% 的用户
ListNode* reverseBetween(ListNode* head, int m, int n) {
    int cnt = 1;
    ListNode *res;

    ListNode *iter = head;
    while(cnt < m){
        iter = iter->next;
        cnt++;
    }//此时iter指向需要反转的第一个节点
    ListNode *revhead = iter;

    while(cnt < n){
        iter = iter->next;
        cnt++;
    }//此时iter指向需要反转的最后一个节点
    iter = iter->next;
    ListNode *end = iter;

    while(revhead != end){
        ListNode *t = revhead->next;
        revhead->next = iter;
        iter = revhead;//维持iter为要反转的节点之后节点的首节点
        revhead = t;
    }
    if(m == 1)return iter;

    ListNode *i = head;
    cnt = 1;
    while(cnt < m - 1){
        i = i->next;
        cnt++;
    }
    i->next = iter;
    return head;
}

int main(){
    cout << 1 << endl;
}