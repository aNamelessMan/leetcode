#include<bits/stdc++.h>
#include "ListNode.hpp"
// 执行用时：28 ms, 在所有 C++ 提交中击败了88.23% 的用户
// 内存消耗：15 MB, 在所有 C++ 提交中击败了9.91% 的用户
using namespace std;

bool isPalindrome(ListNode* head) {
    if(!head || !(head->next))return true;
    //先快慢指针法找到终点，翻转后半部分，再两个指针遍历比较，比较麻烦，以后再看
    //下面是简单做法
    vector<int> lst;
    while(head){
        lst.push_back(head->val);
        head = head->next;
    }
    int h = 0, t = lst.size() - 1;
    while(h != t && h != t + 1){
        if(lst[h] != lst[t])return false;
        h++;
        t--;
    }
    return true;
}

int main(){
    cout << 1 << endl;
}