#include<bits/stdc++.h>
using namespace std;
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.2 MB, 在所有 C++ 提交中击败了88.08% 的用户
bool isValid(string s) {
    stack<char> stk;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')stk.push(s[i]);
        else if(!stk.empty() && s[i] == ')'){//调用top前需要判断是否为空
            if(stk.top() == '(')stk.pop();
            else return false;
        }else if(!stk.empty() && s[i] == ']'){
            if(stk.top() == '[')stk.pop();
            else return false;
        }else if(!stk.empty() && s[i] == '}'){
            if(stk.top() == '{')stk.pop();
            else return false;
        }else
            return false;
    }
    return stk.empty();
}

int main(){
    cout << isValid("]") << endl;
}