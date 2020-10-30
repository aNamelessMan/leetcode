#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：4 ms, 在所有 C++ 提交中击败了99.83% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了5.01% 的用户
ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next))return head;
    stack<int> stk;
    while(head){
        stk.push(head->val);
        head = head->next;
    }
    ListNode *res = new ListNode(stk.top());
    stk.pop();
    ListNode *p = res;
    while(!stk.empty()){
        p->next = new ListNode(stk.top());
        p = p->next;
        stk.pop();
    }
    return res;
}

int main(){
    cout << 1 << endl;
}