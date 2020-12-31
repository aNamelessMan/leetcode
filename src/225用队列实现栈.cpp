#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.2 MB, 在所有 C++ 提交中击败了44.97% 的用户
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> &q = q1.empty() ? q2:q1;
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> &q = q1.empty() ? q2:q1;
        queue<int> &eq = q2.empty() ? q2:q1;

        while(q.size() > 1){
            eq.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())return q2.back();
        else return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


int main(){
    cout << 1 << endl;
}