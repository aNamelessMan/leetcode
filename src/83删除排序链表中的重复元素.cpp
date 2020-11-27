#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：16 ms, 在所有 C++ 提交中击败了59.53% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了16.49% 的用户
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next)return head;
    ListNode *res = head;
    while(head){
        ListNode *pre = head;
        while(head && head->val == pre->val){
            head = head->next;
        }
        pre->next = head;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}