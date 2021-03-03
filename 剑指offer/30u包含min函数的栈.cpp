#include <bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了95.34% 的用户
// 内存消耗：14.8 MB, 在所有 C++ 提交中击败了50.80% 的用户
class MinStack {
private:
    vector<int> stk;
    vector<int> m;//m[i]记录栈大小为i + 1时的最小值在栈中的下标
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(stk.empty()){
            m.push_back(0);
        }else{
            if(x < stk[m[m.size() - 1]]){
                m.push_back(m.size());
            }else{
                m.push_back(m.back());
            }
        }
        stk.push_back(x);
    }
    
    void pop() {
        stk.pop_back();
        m.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int min() {
        return stk[m.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */