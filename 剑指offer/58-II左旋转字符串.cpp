#include <bits/stdc++.h>
using namespace std;

// 执行用时：4 ms, 在所有 C++ 提交中击败了80.23% 的用户
// 内存消耗：6.8 MB, 在所有 C++ 提交中击败了99.37% 的用户
string reverseLeftWords(string s, int n) {
    int sz = s.size();
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    cout << "print sth." << endl;
}