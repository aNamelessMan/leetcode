#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了98.41% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了98.41% 的用户
ListNode* deleteNode(ListNode* head, int val) {
    if(head->val == val)return head->next;
    ListNode* iter = head;
    while(iter->next){
        if(iter->next->val == val){
            iter->next = iter->next->next;
            break;
        }
        iter = iter->next;
    }
    return head;
}

int main(){
    cout << "print sth." << endl;
}