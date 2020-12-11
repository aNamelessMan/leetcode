#include<bits/stdc++.h>
#include "ListNode.hpp"
#include "listOps.hpp"
using namespace std;

// 执行用时：60 ms, 在所有 C++ 提交中击败了93.38% 的用户
// 内存消耗：18.5 MB, 在所有 C++ 提交中击败了38.68% 的用户
//复用第28题代码
ListNode * middleNode(ListNode * head) {
    if(!head)return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reorderList(ListNode* head) {
    if(!head || !head->next || !head->next->next)return;

    ListNode* mid = middleNode(head);
    ListNode* aftermid = mid->next;

    queue<ListNode*> q;
    stack<ListNode*> s;

    while(head != aftermid){
        q.push(head);
        head = head->next;
    }
    while(aftermid){
        s.push(aftermid);
        aftermid = aftermid->next;
    }

    head = q.front();
    ListNode* t = head;
    q.pop();
    bool sw = false;
    while(!q.empty() || !s.empty()){
        if(sw){
            t->next = q.front();
            q.pop();
        }else{
            t->next = s.top();
            s.pop();
        }
        t = t->next;
        sw = !sw;
    }
    t->next = nullptr;
}

int main(){
    vector<int> l = {1, 2, 3, 4};
    ListNode* lst = constructList(l);
    reorderList(lst);
    printList(lst);
}