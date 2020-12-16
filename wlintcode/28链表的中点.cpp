#include<bits/stdc++.h>
#include "../src/ListNode.hpp"
using namespace std;

//您的提交打败了 34.20% 的提交!
ListNode * middleNode(ListNode * head) {
    if(!head)return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    cout << 1 << endl;
}