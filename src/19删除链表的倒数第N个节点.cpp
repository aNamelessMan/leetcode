#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：12 ms, 在所有 C++ 提交中击败了53.25% 的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了5.05% 的用户
ListNode* removeNthFromEnd(ListNode* head, int n) {
    //让ace先走n步，这样当ace走到尾节点时（即ace->next为空时时），nPlus1走到要删除节点的前一个节点
    //注意处理只有1个节点的情况和删除第一个节点的情况（此时ace直接走到nullptr）
    ListNode* ace = head;
    ListNode* nPlus1 = head;
    if(!head->next)return nullptr;//只有一个节点
    for(int i = 0; i < n; i++)ace = ace->next;
    if(!ace)return head->next;//删除第一个节点
    while(ace->next){
        ace = ace->next;
        nPlus1 = nPlus1->next;
    }
    nPlus1->next = nPlus1->next->next;
    return head;
}

int main(){
    cout << 1 << endl;
}