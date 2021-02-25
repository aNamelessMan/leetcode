#include<bits/stdc++.h>
using namespace std;

//简单解法见剑指offer第20题
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了20.27% 的用户
//一道没有难度的困难题，但是不知道错误提交了多少次...
bool isNumber(string s) {
    int n = s.size();
    if(n == 0)return false;
    int head = -1, tail = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != ' '){
            head = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] != ' '){
            tail = i;
            break;
        }
    }
    if(head == -1 || tail == -1)return false;
    if(s[head] == '+' || s[head] == '-')head++;
    if(head > tail)return false;
    s = s.substr(head, tail - head + 1);

    n = s.size();
    if(n == 0)return false;

    for(int i = 0; i < n; i++){
        if(s[i] != 'e' && s[i] != '.' && s[i] != '+' && s[i] != '-' && (s[i] > '9' || s[i] < '0'))return false;
    }
    int signidx = -1, eidx = -1, dotidx = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '+' || s[i] == '-'){
            if(signidx != -1)return false;
            else signidx = i;
        }
        if(s[i] == 'e'){
            if(eidx != -1)return false;
            else eidx = i;
        }
        if(s[i] == '.'){
            if(dotidx != -1)return false;
            else dotidx = i;
        }
    }
    if(signidx != 0 && signidx != -1 && signidx - eidx != 1 || signidx == n - 1)return false;
    if(eidx != -1 && eidx < dotidx)return false;
    int f;
    if(signidx == 0)f = 1;
    else f = 0;
    if(eidx == f || eidx == n - 1)return false;
    if(dotidx == f && dotidx == n - 1)return false;
    if(eidx != -1 && dotidx != -1 && eidx - dotidx == 1 && dotidx == f)return false;

    return true;
}

int main(){
    cout << 1 << endl;
}