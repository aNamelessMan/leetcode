#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了98.50% 的用户
// 内存消耗：18.7 MB, 在所有 C++ 提交中击败了69.10% 的用户
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
    return head.next;
}

int main(){
    cout << "print sth." << endl;
}