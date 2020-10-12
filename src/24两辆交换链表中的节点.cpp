#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.5 MB, 在所有 C++ 提交中击败了5.05% 的用户
//定义一个函数专门交换两个节点
//返回交换过后的头指针以便于跟前面的节点连接
//并且尾指针也要保留
ListNode* swap(ListNode* p1, ListNode* p2){
    ListNode* tmp = p2->next;//保存尾指针
    p2->next = p1;
    p1->next = tmp;
    return p2;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* res = head;
    ListNode** f = &res;//f的作用是将next和后面交换过的节点接上，因为修改的内容是一个指针，因此需要二级指针
    //引用只能绑定一次，不能修改，所以指针是必要的
    ListNode* p1 = res;
    if(!p1 || !(p1->next))return head;
    ListNode* p2 = p1->next;
    while(1){
        *f = swap(p1, p2);
        if(p1->next && p1->next->next){//注意颠倒过后现在是p1在后面，而且更新后仍然要恢复p1在前面
            f = &(p1->next);
            p1 = p1->next;
            p2 = p1->next;

        }else{
            break;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}