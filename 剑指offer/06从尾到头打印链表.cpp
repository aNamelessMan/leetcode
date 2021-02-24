#include <bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了92.18% 的用户
// 内存消耗：8.4 MB, 在所有 C++ 提交中击败了93.63% 的用户
vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    while(head){
        res.push_back(head->val);
        head = head->next;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cout << "print sth." << endl;
}