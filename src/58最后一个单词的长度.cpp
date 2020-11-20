#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.9 MB, 在所有 C++ 提交中击败了6.13% 的用户
int lengthOfLastWord(string s) {
    int n = s.size(), i = 0, res = 0;
    while(i < n){
        while(i < n && s[i] == ' ')i++;
        if(i == n)break;//防止末尾以' '结尾
        res = 0;
        while(i < n && s[i] != ' '){
            res++;
            i++;
        }
    }
    return res;
}

int main(){
    cout << 1 << endl;
}