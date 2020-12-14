#include<bits/stdc++.h>
#include "ListNode.hpp"
#include "listOps.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了89.87% 的用户
// 内存消耗：12.2 MB, 在所有 C++ 提交中击败了5.06% 的用户
ListNode* reverse(ListNode* head){
    if(!head)return head;
    stack<ListNode*> stk;
    while(head){
        stk.push(head);
        head = head->next;
    }
    ListNode* res = stk.top(), *t = res;
    t->next = nullptr;
    stk.pop();
    while(!stk.empty()){
        t->next = stk.top();
        stk.pop();
        t = t->next;
        t->next = nullptr;
    }
    return res;
}//返回头指针，尾指针就是传进来的参数head

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* res = nullptr, *t = head;
    int cnt = 0;
    while(t && cnt < k - 1){
        t = t->next;
        cnt++;
    }//出循环时cnt为k - 1，head指向第k个节点
    ListNode* pre = t;
    ListNode* tail = nullptr;
    if(t){
        t = t->next;
        pre->next = nullptr;
        res = reverse(head);
        tail = head;//翻转后这组序列尾就是原来的头
        head = t;
    }else{
        return head;
    }

    while(t){
        cnt = 0;
        while(t && cnt < k - 1){
            t = t->next;
            cnt++;
        }
        pre = t;
        if(t){
            t = t->next;
            pre->next = nullptr;
            tail->next = reverse(head);
            tail = head;//翻转后这组序列尾就是原来的头
            head = t;
        }else{
            tail->next = head;
            return res;
        }
    }

    return res;
}

int main(){
    vector<int> l = {1,2,3,4,5};
    ListNode* head = constructList(l);
    ListNode* res = reverseKGroup(head, 3);
    printList(res);
}