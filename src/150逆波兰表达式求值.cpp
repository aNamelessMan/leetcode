#include<bits/stdc++.h>
using namespace std;

// 执行用时：20 ms, 在所有 C++ 提交中击败了68.52% 的用户
// 内存消耗：11.4 MB, 在所有 C++ 提交中击败了5.03% 的用户
int evalRPN(vector<string>& tokens) {
    stack<string> s;
    int n = tokens.size();
    for(int i = 0; i < n; i++){
        if(tokens[i] == "+"){
            int n2 = atoi(s.top().c_str());
            s.pop();
            int n1 = atoi(s.top().c_str());
            s.pop();
            s.push(to_string(n1 + n2));
        }else if(tokens[i] == "-"){
            int n2 = atoi(s.top().c_str());
            s.pop();
            int n1 = atoi(s.top().c_str());
            s.pop();
            s.push(to_string(n1 - n2));
        }else if(tokens[i] == "*"){
            int n2 = atoi(s.top().c_str());
            s.pop();
            int n1 = atoi(s.top().c_str());
            s.pop();
            s.push(to_string(n1 * n2));
        }else if(tokens[i] == "/"){
            int n2 = atoi(s.top().c_str());
            s.pop();
            int n1 = atoi(s.top().c_str());
            s.pop();
            s.push(to_string(n1 / n2));
        }else{
            s.push(tokens[i]);
        }
    }
    return atoi(s.top().c_str());
}

int main(){
    cout << 1 << endl;
}