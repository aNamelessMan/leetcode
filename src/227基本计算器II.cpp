#include<bits/stdc++.h>
#include <functional>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了89.10% 的用户
// 内存消耗：8.9 MB, 在所有 C++ 提交中击败了32.04% 的用户
//很麻烦，没调试器不一定写得出来...
int calculate(string s) {
    //先处理成只含加减号的等式
    string ss;
    for(char c:s){
        if(c != ' ')
            ss += c;
    }

    int i = 0, n = ss.size();
    string sss;
    while(i < n){
        string lhs;
        while(ss[i] >= '0' && ss[i] <= '9' && i < n){
            lhs += ss[i];
            i++;
        }

        char op = ss[i];
        i++;

        while((op == '*' || op == '/') && i < n){
            string rhs;
            while(ss[i] >= '0' && ss[i] <= '9' && i < n){
                rhs += ss[i];
                i++;
            }
            int l = atoi(lhs.c_str());
            int r = atoi(rhs.c_str());
            if(op == '*'){
                lhs = to_string(l * r);
            }else{
                lhs = to_string(l / r);
            }
            op = ss[i];
            i++;
        }
        sss += lhs;
        sss += op;
    }

    n = sss.size();
    i = 0;
    int res;
    string tmps;
    while(i < n && ((sss[i] >= '0' && sss[i] <= '9') || (i == 0))){
        tmps += sss[i];
        i++;
    }
    res = atoi(tmps.c_str());

    while(i < n){
        char op = sss[i];
        i++;
        int st = i;
        tmps.clear();
        while(i < n && ((sss[i] >= '0' && sss[i] <= '9') || (i == st))){
            tmps += sss[i];
            i++;
        }
        if(op == '+'){
            res += atoi(tmps.c_str());
        }else{
            res -= atoi(tmps.c_str());
        }
    }

    return res;
}

int main(){
    cout << calculate("2*3*4") << endl;
    cout << calculate("3+2*2") << endl;
    cout << calculate(" 3/2 ") << endl;
    cout << calculate(" 3+5 / 2 ") << endl;
}