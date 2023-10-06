#include <bits/stdc++.h>

#include "ListNode.hpp"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution230926 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* prev;
        ListNode* cur;
        ListNode* next;
        prev = nullptr;
        cur = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了97.79% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了79.75% 的用户
// 2021.3.4二刷
ListNode* reverseList(ListNode* head) {
    ListNode* reversed = nullptr;  // reversed为已翻转的链表的头指针
    while (head) {
        ListNode* next = head->next;
        head->next = reversed;
        reversed = head;
        head = next;
    }
    return reversed;
}

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.83% 的用户
// 内存消耗：9.1 MB, 在所有 C++ 提交中击败了5.01% 的用户
ListNode* reverseList(ListNode* head) {
    if (!head || !(head->next)) return head;
    stack<int> stk;
    while (head) {
        stk.push(head->val);
        head = head->next;
    }
    ListNode* res = new ListNode(stk.top());
    stk.pop();
    ListNode* p = res;
    while (!stk.empty()) {
        p->next = new ListNode(stk.top());
        p = p->next;
        stk.pop();
    }
    return res;
}

int main() { cout << 1 << endl; }