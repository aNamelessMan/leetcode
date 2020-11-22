#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了93.24% 的用户
// 内存消耗：11.9 MB, 在所有 C++ 提交中击败了5.02% 的用户
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k == 0)return head;
    int sz = 1;
    ListNode* t = head;
    while(t->next){
        t = t->next;
        sz++;
    }
    k %= sz;
    if(k == 0)return head;//注意如果提前返回要在修改尾节点之前
    t->next = head;
    k = sz - k - 1;//注意是右转，所以要断开从左往右数第sz - k个，而不是第k个
    t = head;
    while(k){
        t = t->next;
        k--;
    }
    ListNode* res = t->next;
    t->next = nullptr;
    return res;
}

int main(){
    cout << 1 << endl;
}