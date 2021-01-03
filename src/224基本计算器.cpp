#include<bits/stdc++.h>
using namespace std;

// 执行用时：48 ms, 在所有 C++ 提交中击败了30.39% 的用户
// 内存消耗：10.7 MB, 在所有 C++ 提交中击败了31.76% 的用户
//没什么难度，就是很繁琐，花了很长时间
int calculate(string s) {
    string ss;
    ss += '(';
    s += ')';

    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] != ' ')
            ss += s[i];
    }
    stack<char> stk;
    stk.push(ss[0]);
    int c = 1;
    while(1){
        if(ss[c] != ')'){
            stk.push(ss[c]);
            c++;
        }else{
            c++;
            string exp;

            while(stk.top() != '('){
                exp += stk.top();
                stk.pop();
            }
            stk.pop();

            reverse(exp.begin(), exp.end());

            int res;
            string ress;
            int i = 0, n = exp.size();
            while(exp[i] >= '0' && exp[i] <= '9' && i < n){
                ress += exp[i];
                i++;
            }
            res = atoi(ress.c_str());

            while(i < n){
                char op = exp[i];
                i++;
                string rhs;
                int st = i;
                while(((exp[i] >= '0' && exp[i] <= '9') || (i == st)) && i < n){
                    rhs += exp[i];
                    i++;
                }
                int r = atoi(rhs.c_str());

                switch (op)
                {
                case '+':
                    res += r;
                    break;
                case '-':
                    res -= r;
                    break;
                }
            }
            if(stk.empty())return res;
            ress = to_string(res);
            for(char c:ress){
                stk.push(c);
            }
        }
    }
}

int main(){
    cout << calculate("2-(5-6)") << endl;
    cout << calculate(" 2-1 + 2 ") << endl;
    cout << calculate("1 + 1") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
}