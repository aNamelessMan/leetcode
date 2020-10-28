#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：8 ms, 在所有 C++ 提交中击败了95.36% 的用户
// 内存消耗：7.8 MB, 在所有 C++ 提交中击败了15.33% 的用户
//快慢指针
bool hasCycle(ListNode *head) {
    if(!head || !head->next || !head->next->next)return false;//每次使用->都要想想 -> 左边是不是可能为空指针
    ListNode* f = head->next->next;
    ListNode* s = head->next;
    while(f != nullptr && f != s){
        s = s->next;
        if(f->next == nullptr){
            f = f->next;
            break;
        }
        f = f->next->next;
    }
    return (f != nullptr);

}

int main(){
    cout << 1 << endl;
}