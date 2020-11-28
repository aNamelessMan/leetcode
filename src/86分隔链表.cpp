#include<bits/stdc++.h>
#include "ListNode.hpp"
#include "listOps.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.63% 的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了7.25% 的用户
//难度不大，就是比较繁琐
ListNode* partition(ListNode* head, int x) {
    if(!head || !head->next)return head;
    ListNode *befH = nullptr;
    ListNode *aftH = nullptr;

    ListNode *iter = head;
    while(iter && iter->val >= x){
        iter = iter->next;
    }
    //循环结束后iter应该为空    或  指向第一个小于x的节点
    if(!iter)return head;//为空说明所有节点都大于等于x
    befH = iter;

    iter = head;
    while(iter && iter->val < x){
        iter = iter->next;
    }
    //循环结束后iter应该为空    或  指向第一个大于等于x的节点
    if(!iter)return head;//为空说明所有节点都小于x
    aftH = iter;

    ListNode *res = befH;
    ListNode *t = aftH;
    while(head){
        if(head->val < x){
            if(befH != head){
                befH->next = head;
                befH = befH->next;
            }
            head = head->next;
            befH->next = nullptr;
        }else{
            if(aftH != head){
                aftH->next = head;
                aftH = aftH->next;
            }
            head = head->next;
            aftH->next = nullptr;
        }
    }
    befH->next = t;

    return res;
}

int main(){
    vector<int> v = {1,4,3,2,5,2};
    ListNode *s = constructList(v);
    printList(s);
    printList(partition(s, 3));
    
    v = {2, 1};
    s = constructList(v);
    printList(s);
    printList(partition(s, 2));
}