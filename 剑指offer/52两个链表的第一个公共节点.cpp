#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了84.97% 的用户
// 内存消耗：14.2 MB, 在所有 C++ 提交中击败了78.02% 的用户
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA, *p2 = headB;
    while(p1 != p2){
        if(p1)p1 = p1->next;
        else p1 = headB;
        if(p2)p2 = p2->next;
        else p2 = headA;
    }
    return p1;
}

int main(){
    cout << "print sth." << endl;
}