#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了93.13% 的用户
// 内存消耗：7.6 MB, 在所有 C++ 提交中击败了14.26% 的用户
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next)return head;
    ListNode *res = nullptr;
    ListNode *restail;

    //需要一个指针指向上一个不重复的元素
    while(head){
        ListNode *first = head;
        int cnt = 0;
        while(head && head->val == first->val){
            head = head->next;
            cnt++;
        }
        if(cnt == 1){//找到第一个不重复的元素，此时headh指向res后一个元素
            res = first;
            restail = res;
            restail->next = nullptr;
            break;
        }
    }

    while(head){
        ListNode *first = head;
        int cnt = 0;
        while(head && head->val == first->val){
            head = head->next;
            cnt++;
        }
        if(cnt == 1){
            restail->next = first;
            restail = restail->next;
            restail->next = nullptr;//注意尾后指针置空，否则如果最后一个元素是重复的，会因为restail->next未操作仍指向原来的重复的元素
        }
    }

    return res;
}

int main(){
    cout << 1 << endl;
}