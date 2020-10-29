#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：104 ms, 在所有 C++ 提交中击败了12.00% 的用户
// 内存消耗：17.8 MB, 在所有 C++ 提交中击败了5.02% 的用户
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> sl;
    while(headA){
        sl.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(sl.count(headB))return headB;
        headB = headB->next;
    }
    return nullptr;
}

int main(){
    cout << 1 << endl;
}