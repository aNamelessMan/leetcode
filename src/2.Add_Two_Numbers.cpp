#include<bits/stdc++.h>
#include "../dataStruc/ListNode.hpp"
#include "../dataStruc/listOps.hpp"
using namespace std;

// 执行用时：24 ms, 在所有 C++ 提交中击败了74.91%的用户
// 内存消耗：69.4 MB, 在所有 C++ 提交中击败了47.78%的用户
// 通过测试用例：1568 / 1568
ListNode* addTwoNumbers4(ListNode* l1, ListNode* l2) {
    ListNode* ret = new ListNode;
    ListNode* iter = ret;
    int carry = 0;
    while(l1 || l2 || carry){
        int t = carry;
        if(l1){
            t += l1->val;
        }
        if(l2){
            t += l2->val;
        }
        carry = t / 10;
        t = t % 10;
        iter->next = new ListNode(t, nullptr);
        iter = iter->next;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }
    return ret->next;
}


// 执行用时：36 ms, 在所有 C++ 提交中击败了75.57% 的用户
// 内存消耗：69.5 MB, 在所有 C++ 提交中击败了35.50% 的用户
ListNode* thirdAddTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode vn, *iter = &vn;
    while(l1 && l2){
        int v = l1->val + l2->val + carry, res = v % 10;
        carry = v / 10;
        iter->next = new ListNode(res);

        iter = iter->next;
        l1 = l1->next;
        l2= l2->next;
    }
    ListNode *l = l1?l1:l2;
    while(l){
        int v = l->val + carry, res = v % 10;
        carry = v / 10;
        iter->next = new ListNode(res);

        iter = iter->next;
        l = l->next;
    }
    if(carry){
        iter->next = new ListNode(carry);
        iter = iter->next;
    }
    return vn.next;
}

// 执行用时：28 ms, 在所有 C++ 提交中击败了99.05% 的用户
// 内存消耗：69.4 MB, 在所有 C++ 提交中击败了90.67% 的用户
//2021.1.24二刷的解法
/*
    1.这题首先是不要先把数读出来再加
    2.注意结果首节点的处理，不要重复或漏掉
    3.全部计算完后，还要看看进位值是否为0，若不为0还要加一个值为1的节点
*/
ListNode* secondAddTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, sum = 0;
    if(l1 == nullptr)return l2;
    if(l2 == nullptr)return l1;

    ListNode* head = nullptr, * iter = head;
    while(l1 && l2){
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        sum %= 10;

        if(head){//区分是否为头节点
            iter->next = new ListNode(sum);
            iter = iter->next;
        }else{
            head = new ListNode(sum);
            iter = head;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 || l2){
        ListNode* t = l1!=nullptr?l1:l2;
        while(t){
            sum = t->val + carry;
            carry = sum / 10;
            sum %= 10;
            iter->next = new ListNode(sum);

            iter = iter->next;
            t = t->next;
        }
    }
    
    if(carry)iter->next = new ListNode(1);

    return head;
}

/*执行用时 :32 ms, 在所有 C++ 提交中击败了67.98% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res;
    int carry = 0;
    if(l1 != NULL && l2 != NULL){
        res = new ListNode(l1->val + l2->val);
        if((l1->val + l2->val) > 9){carry = 1;res->val -= 10;}
    }
    else if(l1 != NULL && l2 == NULL){return l1;}
    else if(l1 == NULL && l2 != NULL){return l2;}
    else{return NULL;}
    ListNode* cur = res;
    while(l1->next != NULL || l2->next != NULL){
        if(l1->next != NULL && l2->next != NULL){
            cur->next = new ListNode(l1->next->val + l2->next->val + carry);
            //carry = 0;
            if((l1->next->val + l2->next->val + carry) > 9){
                carry = 1;
                cur -> next -> val -= 10;
            }
            else{
                carry = 0;
            }

            cur = cur->next;
            l1 = l1 ->next;
            l2 = l2 ->next;
        }
        else if(l1->next == NULL && l2->next != NULL){
            cur->next = l2->next;  
            while(carry != 0){
                if(l2->next == NULL){
                    l2->next = new ListNode(1);
                    return res;
                }
                l2->next->val++;   
                if(l2->next->val > 9){
                    carry = 1;
                    l2->next->val -= 10;
                    l2 = l2->next;
                }   
                else{
                    carry = 0;
                }             
            }
            return res;
        }
        else{
        cur->next = l1->next;  
            while(carry != 0){
                if(l1->next == NULL){
                    l1->next = new ListNode(1);
                    return res;
                }
                l1->next->val++;   
                if(l1->next->val > 9){
                    carry = 1;
                    l1->next->val -= 10;
                    l1 = l1->next;
                }   
                else{
                    carry = 0;
                }             
            }
            return res;
        }
    }
    if(carry != 0){
        cur->next = new ListNode(1);
        return res;
    }
    else{return res;}
}

//2020.10.29日笔试写的解法，这题不能先把两个数读出来再加起来，然后建链表，会有特别长的用例过不去...
ListNode* myaddTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1)return l2;
    if(!l2)return l1;
    int c = 0;
    int t = l1->val + l2->val;
    if(t > 9){
        c = 1;
        t %= 10;
    }
    ListNode* head = new ListNode(t);
    ListNode*p = head;
    l1 = l1->next;
    l2 = l2->next;
    while(l1 && l2){
        t = l1->val + l2->val + c;
        if(t > 9){
            c = 1;
            t %= 10;
        }else{
            c = 0;
        }
        p->next = new ListNode(t);
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode* p1 = nullptr;
    if(l2)p1 = l2;
    else if(l1)p1 = l1;

    while(p1){
        t = p1->val + c;
        if(t > 9){
            c = 1;
            t %= 10;
        }else{
            c = 0;
        }
        p->next = new ListNode(t);
        p = p->next;
        p1 = p1->next;
    }
    if(c)p->next = new ListNode(1);
    return head;
}

int main(){
    ListNode *l1 = constructList(); 
    ListNode *l2 = constructList();
    ListNode *res = thirdAddTwoNumbers(l1, l2);
    printList(res);
}