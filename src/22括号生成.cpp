#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：11.2 MB, 在所有 C++ 提交中击败了79.03% 的用户
//nofl 一定大于等于 nofr
void dfs(int nofl, int nofr, int l, string &t, vector<string>& res, int n){
    if(l == 0){
        res.push_back(t);
    }else{
        if(nofl == nofr){
            t += "(";
            dfs(nofl + 1, nofr, l, t, res, n);
            t.pop_back();
        }else{
            if(nofl < n){//否则会无限递归下去
                t += "(";
                dfs(nofl + 1, nofr, l, t, res, n);
                t.pop_back();
            }
            t += ")";
            dfs(nofl, nofr + 1, l - 1, t, res, n);
            t.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string t;
    dfs(0, 0, n, t, res, n);
    return res;
}

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：11.1 MB, 在所有 C++ 提交中击败了89.04% 的用户
//计算s的过程中s的左括号个数>=右括号个数
void dfs(int numL, int numR, int nLeft, string &s, vector<string> &res, int n){
    //注意同一层函数调用中，递归出来后需要将状态完全复原，包括s/numL/numR/nLeft，才能进行下一次递归
    //所以可以看到在递归前后这些状态的改变是成对出现的
    //类似的还有第17题
    if(nLeft){
        if(numL == numR){
            s += '(';
            numL++;
            dfs(numL, numR, nLeft, s, res, n);
            numL--;
            s.pop_back();
        }else{
            if(numL < n){
                s += '(';
                numL++;
                dfs(numL, numR, nLeft, s, res, n);
                numL--;
                s.pop_back();

                s += ')';
                numR++;
                nLeft--;
                dfs(numL, numR, nLeft, s, res, n);
                nLeft++;
                numR--;
                s.pop_back();
            }else{
                s += ')';
                numR++;
                nLeft--;
                dfs(numL, numR, nLeft, s, res, n);
                nLeft++;
                numR--;
                s.pop_back();
            }
        }
    }else{
        res.push_back(s);
    }
}

vector<string> fstgenerateParenthesis(int n) {
    vector<string> res;
    string s = "";
    dfs(0, 0, n, s, res, n);
    return res;
}

int main(){
    generateParenthesis(3);
    cout << 1 << endl;
}