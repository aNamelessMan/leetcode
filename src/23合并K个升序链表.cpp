#include<bits/stdc++.h>
#include "ListNode.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了94.50% 的用户
// 内存消耗：13 MB, 在所有 C++ 提交中击败了79.91% 的用户
//2021.2.25
//使用优先队列  复杂度为O(nlogk)n是总元素个数，k是链表个数，也就是优先队列大小
struct node{//包装一下ListNode这样可以在优先队列里比较节点大小
    node(ListNode* ln):l(ln){

    }
    ListNode* l;
    bool operator < (const node&rhs) const{//注意此处必须有const限定，不然无法被优先队列调用
        return l->val > rhs.l->val;//C++默认优先队列是大顶堆，此处修改为小顶堆
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<node> q;
    for(auto l:lists){
        if(l)q.push(node(l));
    }

    ListNode res, *iter = &res;//创建一个虚节点，也就是val无意义的节点，最终返回res.next，使用这种手法可以不用特殊处理首节点
    while(!q.empty()){
        auto t = q.top().l;
        q.pop();
        iter->next = t;
        iter = iter->next;
        if(iter->next){
            q.push(iter->next);
        }
    }
    return res.next;
}

// 执行用时：1760 ms, 在所有 C++ 提交中击败了5.00% 的用户
// 内存消耗：13.5 MB, 在所有 C++ 提交中击败了21.86% 的用户
ListNode* BFmergeKLists(vector<ListNode*>& lists) {
    //遍历找出每个链表头部最小的那个加入结果，并将其头部后移
    //注意使用INT_MAX/MIN这种值时后续不要因为进行加减运算导致溢出，一般只能直接赋值
    int min = INT_MAX;
    //找出最小值并初始化res
    ListNode *res = nullptr;
    ListNode *p = nullptr;
    for(auto &h:lists){
        if(h && h->val < min){
            min = h->val;
        }
    }
    if(min == INT_MAX)return nullptr;//判断lists是否为空或只存了空指针
    for(auto &h:lists){
        if(h && h->val == min){
            res = new ListNode(min);
            p = res;
            h = h->next;
            break;
        }
    }
    while(min != INT_MAX){//如果没有剩余值即min不再更新
        min = INT_MAX;
        for(auto &h:lists){
            if(h && h->val < min){
                min = h->val;
            }
        }
        for(auto &h:lists){
            if(h && h->val == min){
                p->next = new ListNode(min);
                p = p->next;
                h = h->next;
                break;
            }
        }
    }
    return res;
}
// 执行用时：1252 ms, 在所有 C++ 提交中击败了5.00% 的用户
// 内存消耗：13.6 MB, 在所有 C++ 提交中击败了21.59% 的用户
//还是很慢
//应该使用优先队列，懒得改了
ListNode* alsoBFmergeKLists(vector<ListNode*>& lists) {
    //最简单的改进就是增加一个记录最小指针的指针
    //注意vector里存的是头指针，想要修改头指针需要一个二级指针
    ListNode **minp = nullptr;
    int min = INT_MAX;
    ListNode *res = nullptr;
    ListNode *p = nullptr;
    for(auto &h:lists){
        if(h && h->val < min){
            min = h->val;
            minp = &h;//不能写成*minp = h;因为minp是空指针不指向任何有效内存，自然不能用来访问内存
        }
    }
    if(min == INT_MAX)return nullptr;//判断lists是否为空或只存了空指针

    res = new ListNode(min);
    p = res;
    *minp = (*minp)->next;

    while(min != INT_MAX){//如果没有剩余值即min不再更新
        min = INT_MAX;
        for(auto &h:lists){
            if(h && h->val < min){
                min = h->val;
                minp = &h;
            }
        }
        if(min != INT_MAX){
            p->next = new ListNode(min);
            p = p->next;
            *minp = (*minp)->next;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}