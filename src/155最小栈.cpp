#include<bits/stdc++.h>
using namespace std;
// 执行用时：32 ms, 在所有 C++ 提交中击败了98.99% 的用户
// 内存消耗：14.6 MB, 在所有 C++ 提交中击败了5.45% 的用户
vector<int> stk;
vector<int> m;//m记录当前栈里的最小元素下标
/** initialize your data structure here. */
void MinStack() {
        
}
    
void push(int x) {
    if(m.empty()){
        stk.push_back(x);
        m.push_back(0);
    }
    else{
        if(x < stk[m[m.size() - 1]]){
            m.push_back(stk.size());
        }else{
            m.push_back(m[m.size() - 1]);
        }
        stk.push_back(x);
    }
}
    
void pop() {
    stk.pop_back();
    m.pop_back();
}
    
int top() {
    return stk[stk.size() - 1];
}
    
int getMin() {
    return stk[m[m.size() - 1]];
}

int main(){
    cout << 1 << endl;
}