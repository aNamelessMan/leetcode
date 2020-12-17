#include<bits/stdc++.h>
using namespace std;

// 执行用时：12 ms, 在所有 C++ 提交中击败了82.77% 的用户
// 内存消耗：9.6 MB, 在所有 C++ 提交中击败了53.56% 的用户
//递归解法
// 简单的说，就是 s1 和 s2 是 scramble 的话，那么必然存在一个在 s1 上的长度 l1，
// 将 s1 分成 s11 和 s12 两段，同样有 s21 和 s22，那么要么 s11 和 s21 是 scramble 的并且 s12 和 s22 是 scramble 的；
// 要么 s11 和 s22 是 scramble 的并且 s12 和 s21 是 scramble 的。
bool isScramble(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    if(m != n)return false;
    if(s1 == s2)return true;

    string str1 = s1, str2 = s2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if(str1 != str2)return false;

    for(int i = 1; i < m; i++){//i是第一个字符串的长度
        string s11 = s1.substr(0, i);
        string s12 = s1.substr(i, m - i);
        string s21 = s2.substr(0, i);
        string s22 = s2.substr(i, m - i);
        if(isScramble(s11, s21) && isScramble(s12, s22))return true;
        s21 = s2.substr(0, m - i);
        s22 = s2.substr(m - i, i);
        if(isScramble(s11, s22) && isScramble(s12, s21))return true;
    }
    return false;
}


int main(){
    cout << 1 << endl;
}