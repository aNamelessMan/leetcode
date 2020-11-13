#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了44.92% 的用户
// 内存消耗：10.8 MB, 在所有 C++ 提交中击败了5.24% 的用户
ListNode* oddEvenList(ListNode* head) {
    //只增加了四个指针  空间复杂度O(1)
    //遍历一遍，原地修改，时间复杂度O(n)
    if(!head || !head->next || !head->next->next)return head;
    ListNode *res = head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenhead = even;
    while(1){
        if(odd->next && odd->next->next){
            odd->next = odd->next->next;
            odd = odd->next;
        }else if(odd->next){
            odd->next = evenhead;
            break;
        }else{
            odd->next = evenhead;
            break;
        }
        if(even->next && even->next->next){
            even->next = even->next->next;
            even = even->next;
        }else if(even->next){
            even->next = nullptr;
        }else{
            break;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}