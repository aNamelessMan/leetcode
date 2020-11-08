#include<bits/stdc++.h>
#include "../src/ListNode.hpp"
using namespace std;

//您的提交打败了 6.23% 的提交!
int countNodesII(ListNode * head) {
    int res = 0;
    while(head){
        if(head->val > 0 && head->val % 2)res++;
        head = head->next;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}