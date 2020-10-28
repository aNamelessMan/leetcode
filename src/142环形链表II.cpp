#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了67.95% 的用户
// 内存消耗：7.7 MB, 在所有 C++ 提交中击败了24.53% 的用户
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next || !head->next->next)return nullptr;//每次使用->都要想想 -> 左边是不是可能为空指针
    ListNode* f = head->next->next;
    ListNode* s = head->next;
    while(f != nullptr && f != s){
        s = s->next;
        if(f->next == nullptr){
            f = f->next;
            break;
        }
        f = f->next->next;
    }
    if(f == nullptr)return nullptr;
//在141题基础上，找到两指针相遇后，将一个指针放回起点，然后同时启动，下次相遇点就是环的入口
    s = head;
    while(s != f){
        s = s->next;
        f = f->next;
    }
    return s;
}

int main(){
    cout << 1 << endl;
}