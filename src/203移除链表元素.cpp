#include<bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：36 ms, 在所有 C++ 提交中击败了94.57% 的用户
// 内存消耗：15.1 MB, 在所有 C++ 提交中击败了44.97% 的用户
ListNode* removeElements(ListNode* head, int val) {
    ListNode* res = head;
    while(res && res->val == val)res = res->next;
    if(!res)return res;
    ListNode* pre = res, *iter = res->next;

    while(iter){
        if(iter->val == val){
            pre->next = iter->next;
        }else{
            pre = iter;
        }
        iter = iter->next;
    }

    return res;
}

int main(){
    cout << 1 << endl;
}