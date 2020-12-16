#include<bits/stdc++.h>
#include "../src/ListNode.hpp"
using namespace std;

//您的提交打败了 99.60% 的提交!
vector<int> reverseStore(ListNode * head) {
    stack<int> res;
    while(head){
        res.push(head->val);
        head = head->next;
    }
    vector<int> f;
    while(!res.empty()){
        f.push_back(res.top());
        res.pop();
    }
    return f;
}

int main(){
    cout << 1 << endl;
}