#include <bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
    int n = s.size(), res = 0;
    if(n == 0)return res;
    int l = 0, r = n - 1;
    while(r > l && s[l] == s[r]){
        int c = s[l];
        while(l < r && s[l] == c){
            l++;
        }
        //l--;//注意这一行不要漏  l表示左侧被删除字符的闭边界
        while(l < r && s[r] == c){
            r--;
        }
        //l++;
    }
    return r - l + 1;
}

int main(){
    cout << minimumLength("ca") << endl;//2
    cout << minimumLength("cabaabac") << endl;//0
    cout << minimumLength("aabccabba") << endl;//3
}