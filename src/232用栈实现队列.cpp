#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了43.05% 的用户
//唯一要注意的是pop和peek后要复原原来的顺序，不然相当于将队列颠倒了
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(stk1.empty()){
            stk2.push(x);
        }else{
            stk1.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> &es = stk1.empty() ? stk1 : stk2;
        stack<int> &nes = stk1.empty() ? stk2 : stk1;

        while(!nes.empty()){
            es.push(nes.top());
            nes.pop();
        }
        int res = es.top();
        es.pop();

        while(!es.empty()){
            nes.push(es.top());
            es.pop();
        }  

        return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> &es = stk1.empty() ? stk1 : stk2;
        stack<int> &nes = stk1.empty() ? stk2 : stk1;

        while(!nes.empty()){
            es.push(nes.top());
            nes.pop();
        }
        int res = es.top();
        while(!es.empty()){
            nes.push(es.top());
            es.pop();
        }
        
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    MyQueue myq;
    myq.push(1);
    myq.push(2);
    cout << myq.peek() << endl;
    cout << myq.pop() << endl;
    cout << myq.empty() << endl;
}