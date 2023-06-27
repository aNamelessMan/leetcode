#include<bits/stdc++.h>
using namespace std;

// 20230627 这个写法很清晰，按E/e划分，然后分别判断前后是否符合小数/整数
class Solution {
public:
    bool isExactNo(string s) {
        if(s.size() == 0)return false;
        int i = 0;
        if(s[i] == '-' || s[i] == '+'){
            i++;
        }
        if(i >= s.size())return false;
        while(i < s.size()) {
            if(s[i] > '9' || s[i] < '0')return false;
            i++;
        }
        return true;
    }
    bool isSmallNo(string s) {
        if(s.size() == 0)return false;
        int i = 0;
        if(s[i] == '-' || s[i] == '+'){
            i++;
        }
        if(i >= s.size())return false;

        if(s.substr(i) == ".")return false;
        bool allowDot = true;
        while(i < s.size()) {
            if(s[i] > '9' || s[i] < '0') {
                if(s[i] == '.'){
                    if(allowDot){
                        allowDot = false;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
    bool isNumber(string s) {
        int n = s.size();
        int b = -1, e = -1;
        for(int i = 0; i < n; i++)
        {
            if(s.at(i) != ' ')
            {
                b = i;
                break;
            }
        }
        if(b == -1) return false;
        for(int i = n - 1; i >= 0; i--)
        {
            if(s.at(i) != ' ')
            {
                e = i;
                break;
            }
        }
        int size = e - b + 1;
        string v = s.substr(b, size);
        
        bool hasE = false;
        int eIndex = -1, i = 0;
        while(i < size) {
            if(v[i] == 'e' || v[i] == 'E') {
                hasE = true;
                eIndex = i;
                break;
            }
            i++;
        }
        if(hasE){
            return (isExactNo(v.substr(0, i)) || isSmallNo(v.substr(0, i))) && isExactNo(v.substr(i + 1));
        }else{
            return isExactNo(v) || isSmallNo(v);
        }

    }
};

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