#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：52 ms, 在所有 C++ 提交中击败了43.56% 的用户
// 内存消耗：9.9 MB, 在所有 C++ 提交中击败了10.29% 的用户
ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next)return head;
    int sorted = 1;
    ListNode* sortedTail = head;
    ListNode* unSortedHead = head->next;
    while(unSortedHead){
        ListNode* t = unSortedHead;
        unSortedHead = unSortedHead->next;
        sortedTail->next = unSortedHead;

        if(t->val < head->val){
            t->next = head;
            head = t;
            sorted++;
        }else{
            int cnt = 1;
            ListNode* tras = head;
            while(tras->next && tras->next->val < t->val && cnt < sorted){//找到插入位置的前一个节点
                cnt++;
                tras = tras->next;
            }
            t->next = tras->next;
            tras->next = t;

            if(cnt == sorted)sortedTail = sortedTail->next;//如果是排过序最后的最后一个节点，就需要更新sortedTail
            sorted++;
        }
    }
    return head;
}

int main(){
    cout << 1 << endl;
}