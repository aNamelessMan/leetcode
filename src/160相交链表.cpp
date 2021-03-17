#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：40 ms, 在所有 C++ 提交中击败了99.09% 的用户
// 内存消耗：14.3 MB, 在所有 C++ 提交中击败了78.01% 的用户
/*
如果有交点，双方交换一次后必然同时到达交点处
如果无交点，双方交换一次后必然同时到达nullptr   也就是无交点
因为经过的节点数相同
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pa = headA, *pb = headB;
    while(pa != pb){
        pa = pa == nullptr?headB:pa->next;//注意必须要让pa/pb可以到达nullptr的状态，否则如果没有交点会无限循环下去
        pb = pb == nullptr?headA:pb->next;
    }
    return pa;
}

// 执行用时：104 ms, 在所有 C++ 提交中击败了12.00% 的用户
// 内存消耗：17.8 MB, 在所有 C++ 提交中击败了5.02% 的用户
//暴力解法不满足空间复杂度O(1)
ListNode *BFgetIntersectionNode(ListNode *headA, ListNode *headB) {
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