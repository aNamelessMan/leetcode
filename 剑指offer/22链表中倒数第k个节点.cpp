#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了82.87% 的用户
// 内存消耗：10.3 MB, 在所有 C++ 提交中击败了83.32% 的用户
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* res = head, *prev = res;
    while(k){
        prev = prev->next;
        k--;
    }
    while(prev){
        prev = prev->next;
        res = res->next;
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}