#include<bits/stdc++.h>
#include "ListNode.hpp"
#include "listOps.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了73.83% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了66.57% 的用户
//2021.3.16比较清晰的解法
ListNode* reverse(ListNode* head){
    ListNode* reversed = nullptr;
    while(head){
        ListNode *next = head->next;
        head->next = reversed;
        reversed = head;
        head = next;
    }
    return reversed;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode h, *p = &h;
    while(head){
        int c = 1;
        ListNode* iter = head;
        while(c < k && iter){
            iter = iter->next;
            c++;
        }
        ListNode *next = nullptr;
        if(iter){
            next = iter->next;
            iter->next = nullptr;
            p->next = reverse(head);
            p = head;
            head = next;
        }else{//不足k个则剩余的不作处理，直接接上即可
            p->next = head;
            head = nullptr;
        }
    }
    return h.next;
}

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