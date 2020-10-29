/*执行用时 :32 ms, 在所有 C++ 提交中击败了67.98% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/

#include <vector>
 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
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
};