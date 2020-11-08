#include<bits/stdc++.h>
#include "../src/ListNode.hpp"
using namespace std;

//您的提交打败了 94.80% 的提交!
int countNodes(ListNode * head) {
    int res = 0;
    while(head){
        head = head->next;
        res++;
    }
    return res;
}

int main(){
    cout << 1 << endl;
}