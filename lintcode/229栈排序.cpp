#include<bits/stdc++.h>
using namespace std;

// 您的提交打败了 7.20% 的提交!
void stackSorting(stack<int>& stk) {
    stack<int> res;
    while(!stk.empty()){
        if(res.empty() || stk.top() >= res.top()){
            res.push(stk.top());
            stk.pop();
        }else{
            int t = stk.top();
            stk.pop();
            while(!res.empty() && res.top() > t){
                stk.push(res.top());
                res.pop();
            }
            res.push(t);
        }
    }stk = res;
}

int main(){
    cout << 1 << endl;
}