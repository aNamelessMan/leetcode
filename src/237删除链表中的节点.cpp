#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了99.85% 的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了81.43% 的用户
//2021.3.15
void deleteNode(ListNode* node) {
    while(node->next->next){
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = nullptr;
}

// 执行用时：8 ms, 在所有 C++ 提交中击败了99.61% 的用户
// 内存消耗：8.1 MB, 在所有 C++ 提交中击败了19.76% 的用户
//这题翻译的有问题，直接看英文
//再不给头节点的情况下删除给定节点，就将该节点之后的所有节点向前平移，然后将倒数第二个节点的next置为空即可
void deleteNode(ListNode* node) {
    while(1){
        int n = node->next->val;
        node->val = n;
        if(!node->next->next){
            node->next = nullptr;
            return;
        }
        node = node->next;
    }
}

int main(){
    cout << 1 << endl;
}