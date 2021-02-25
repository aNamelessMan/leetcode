#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：8 ms, 在所有 C++ 提交中击败了77.26% 的用户
// 内存消耗：8 MB, 在所有 C++ 提交中击败了87.66% 的用户
ListNode* reverseList(ListNode* head) {
    ListNode* iter = head, *prev = nullptr;
    while(iter){
        ListNode* n = iter->next;//保存下来这个节点下一行再修改
        iter->next = prev;
        prev = iter;
        iter = n;
    }
    return prev;
}

int main(){
    cout << "print sth." << endl;
}