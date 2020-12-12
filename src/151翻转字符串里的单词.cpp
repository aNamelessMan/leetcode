#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：7.9 MB, 在所有 C++ 提交中击败了41.29% 的用户
string reverseWords(string s) {
    int n = s.size();
    if(n == 0)return s;

    stack<string> stk;
    for(int i = 0; i < n; ){
        while(i < n && s[i] == ' '){
            i++;
        }
        string t;
        while(i < n && s[i] != ' '){
            t.push_back(s[i]);
            i++;
        }
        stk.push(t);
        while(i < n && s[i] == ' '){
            i++;
        }
    }

    string res;
    res += stk.top();
    stk.pop();

    while(!stk.empty()){
        res += ' ';
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main(){
    cout << 1 << endl;
}